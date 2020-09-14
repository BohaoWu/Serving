"""
hwextract lib use case
"""
import paddle_serving_app.reader.hwextract
import sys
if __name__ == '__main__':
    handler = hwextract.HwExtractFrameJpeg(0)
    # 0, gpu card index
    # if you want BGRA Raw Data, plz use HwExtractBGRARaw
    handler.init_handler()
    # init once can decode many videos
    video_file_name = sys.argv[1]
    # for now just support h264 codec
    frame_list = []
    try:
        frame_list = handler.extract_frame(video_file_name, 1)
        # specifiy file name and fps you want to extract, 0 for all frame
    except Exception as e_frame:
        print("Failed to cutframe, exception[%s]" % (e_frame))
        sys.exit(1)
    for item in frame_list:
        print "i am a item in frame_list"
        # do something, for instance
        # jpeg_array = np.array(item, copy=False)
        # img = cv2.imdecode(item, cv2.IMREAD_COLOR)
        # etc.....
        item.free_memory()
        # have to release memory
