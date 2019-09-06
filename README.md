# ofxUniversalMedia

Addon for playing video and images using WMF (Windows), HAP and TurboJPEG.
Also it supports DShow playing (in Windows using class ofPlayer).

Author: Denis Perevalov

## Requirements

* oF 0.10.1

* K-Lite codecs pack for playing MPG4 videos using ofVideoPlayer (ofxUniversalMediaVideoStandard class) 

* addon ofxWMFVideoPlayer (Windows) for WMF player (ofxUniversalMediaVideoWMF class)

* addon ofxHapPlayer for HAP support (ofxUniversalMediaVideoHAP class)

* addon ofxTurboJpeg for working with image sequences using TurboJPEG (ofxUniversalMediaImageTurgoJpeg class).

If you don't need support particular playing method, just not include it to the project.

## Recommendations

Addon allows you to work with video using several methods.
Here is some recommendations about choosing the methos.

* ofxUniversalMediaImageStandard class works with images using ofTexture class; it's based on FreeImage for reading and decoding images on CPU.
It's universal, but not super-fast.
For using for you must to encode your videos to PNG or JPEG sequences, without audio.

* ofxUniversalMediaImageTurgoJpeg class utilizes ofxTurboJpeg addon for reading and decoding JPEG images;
it's based on ofxTurboJpeg and work with JPEGs very fast on CPU.
For using for you must to encode your videos to JPEG sequences, without audio.

* ofxUniversalMediaVideoStandard class utilizes standard ofVideoPlayer class.
In Windows, it uses DirectShow method and loads all video to CPU, so loops work smoothly.
Also, it CPU-intensive. It supports MPG4 (after installing K-lite codecs pack).

* ofxUniversalMediaVideoWMF class uses ofWMFVideoPlayer addon; it's based on Windows Media Foundation API,
so it gives fast and smooth playing because it's modern Windows method for playing videos using GPU, when available. 
It's oF impementation is not super perfect, and as a result, it's not very well syncing and not good for looping videos. 
Also, currently it streams videos from disk, so may work slow when playing many videos simultaneously.
It supports MP4.

* ofxUniversalMediaVideoHAP class uses ofxHapPlayer; it's super fast because uses HAP codec, intended for GPU efficience video playing.
For using it you must to encode your videos to HAP format.

