from audio_reader import AudioFeatureOp 

if __name__ == '__main__':
    local_video_path = 'case.mp4'
    test_op = AudioFeatureOp()
    test_op.extract_audio_from_video(local_video_path)
