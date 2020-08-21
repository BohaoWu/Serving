/*******************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 ******************************************/
/**
 * @file ExtractFrameBGRARaw.h
 * @author chengang06@baidu.com
 * @date 2020-04-16
 **/
#include <cstring>
#include <memory>
#include <string>
#include <sstream>
#include "ExtractFrameBGRARaw.h"
#include "ExtractFrameJpeg.h"
#include <iomanip>

simplelogger::Logger* logger = simplelogger::LoggerFactory::CreateConsoleLogger();
/**
 * @Name:
 *     image_file_writer
 * @Feature:
 *     write image data to file
 * @params
 *     img_data: image_data
 *     file_path: image_file stored path
 *     prefix: image_name prefix
 *     extension: image_file extension name
 * @returns
 *     void
 **/
void inline image_file_writer(baidu::xvision::FrameResult& img_data, std::string file_path,
                              std::string prefix, std::string extension = "raw") {
    std::ofstream f_out(file_path + "/" + prefix + "." + extension,
                        std::ios::binary | std::ios::out);
    f_out.write(reinterpret_cast<char*>(img_data.get_frame()), img_data.len());
    f_out.close();
}
bool parse_cmd_line(int argc, const char* const argv[]) {
    if (argc <= 3) {
        LOG(FATAL)
            << "params error, eg: ./hw_frame_extract /path/to/mp4.mp4 /output/path bgra|jpeg";
        return false;
    }
    if (!strcmp(argv[3], "bgra") && !strcmp(argv[3], "jpeg")) {
        LOG(FATAL) << "unsupported output file format";
        return false;
    }
    return true;
}
int main(int argc, char* argv[]) {
    if (!parse_cmd_line(argc, argv)) {
        return -1;
    }

    baidu::xvision::ExtractFrameBase* extract_frame_handler(nullptr);
    if (strcmp("bgra", argv[3]) == 0) {
        extract_frame_handler = new baidu::xvision::ExtractFrameBGRARaw();
    } else {
        extract_frame_handler = new baidu::xvision::ExtractFrameJpeg();
    }
    auto init_result = extract_frame_handler->init();
    auto result = extract_frame_handler->extract_frame(argv[1], 1);
    int frame_index = 0;
    std::stringstream ss;
    for (auto result_iter = result.begin(); result_iter != result.end(); result_iter++) {
        ss << std::setw(5) << std::setfill('0') << frame_index;
        image_file_writer(*result_iter, argv[2],
                          "image_" + std::to_string(result_iter->width()) + "_" +
                              std::to_string(result_iter->height()) + "_" +
                              ss.str(),
                          argv[3]);
        result_iter->free_memory();
        frame_index++;
        ss.str("");

    }
    return 0;
}
