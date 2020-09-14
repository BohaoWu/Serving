import unittest
from audio_feature_op import AudioFeatureOp 

class TestAudioOp(unittest.TestCase):
    """
    test audio op
    """
    
    def test_extract_audio_from_video(self):
    """
    test extract audio from video 
    """
    local_video_path = 'case.mp4'
    Op = AudioFeatureOp()
    Op.extract_audio_from_video(local_video_path)


if __name__ == '__main__':
    unittest.main()
