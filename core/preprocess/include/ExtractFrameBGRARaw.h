/*******************************************
 *
 * Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
 *
 ******************************************/
/**
 * @file ExtractFrameBGRARaw.h
 * @author chengang06@baidu.com
 * @date 2020-04-15
 **/
#include <string>

#include "ExtractFrameBase.h"
namespace baidu {
namespace xvision {
class ExtractFrameBGRARaw : public ExtractFrameBase {
    /**
     * @name:
     *     ExtractFrameBGRARaw
     * @author:
     *     chengang06@baidu.com
     * @main feature:
     *     extract video and output bgr raw data
     * @example:
     *
     **/
public:
    ExtractFrameBGRARaw(int gpu_index) : ExtractFrameBase(gpu_index){};
    ExtractFrameBGRARaw(){};
    /**
     * @Name:
     *     extract_frame
     * @Feature:
     *     extract video frame frames from video file, 
     * @params
     *     file_path: video local path
     *     n:         n frames per second
     * @returns
     *     IMGDataList
     **/
    IMGDataList extract_frame(const std::string &file_path, int n = 1);
};
}  // namespace xvision
}  // namespace baidu
