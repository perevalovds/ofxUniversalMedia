# ofxUniversalMedia

Addon for playing video and images using WMF (Windows), HAP and TurboJPEG.
Also it supports DShow playing (in Windows using class ofPlayer).

Author: Denis Perevalov

## Requirements

* **oF 0.10.1**

If you don't need support particular playing method, just not include it to the project.

## Description

Addon allows you to work with video using several methods.

You may declare object of **ofxUniversalMedia** class and instanciate it with one of the following classes:
* **ofxUniversalMediaImageStandard** - images decoding with FreeImage,
* **ofxUniversalMediaImageTurgoJpeg** - JPEG images decoding with TurboJpeg,
* **ofxUniversalMediaVideoStandard** - video player using DirectShow in Windows and others - related to oF standard ofVideoPlayer class,
* **ofxUniversalMediaVideoWMF** - video player using WFM (Windows),
* **ofxUniversalMediaVideoHAP** - video player using HAP codec.

Also, you can use this classes directly.


Below is some recommendations about choosing the appropriate class method for your needs.

## ofxUniversalMediaImageStandard class

**ofxUniversalMediaImageStandard** class works with images using ofTexture class; it's based on FreeImage for reading and decoding images on CPU.
It's universal, but not super-fast.
For using for you must to encode your videos to PNG or JPEG sequences, without audio.


## ofxUniversalMediaImageTurgoJpeg class

**ofxUniversalMediaImageTurgoJpeg** class utilizes ofxTurboJpeg addon for reading and decoding JPEG images;
it's based on ofxTurboJpeg and work with JPEGs very fast on CPU.
For using for you must to encode your videos to JPEG sequences, without audio.

It requires **ofxTurboJpeg** addon.

## ofxUniversalMediaVideoStandard class

**ofxUniversalMediaVideoStandard** class utilizes standard **ofVideoPlayer** class.
In Windows, it uses DirectShow method and loads all video to CPU, so loops work smoothly.
Also, it CPU-intensive. It supports MPG4 (after installing K-lite codecs pack).

## ofxUniversalMediaVideoWMF class

It requires **K-Lite** codecs pack for playing MPG4 videos.

**ofxUniversalMediaVideoWMF** class uses ofWMFVideoPlayer addon; it's based on Windows Media Foundation API,
so it gives fast and smooth playing because it's modern Windows method for playing videos using GPU, when available. 
It's oF impementation is not super perfect, and as a result, it's not very well syncing and not good for looping videos. 
Also, currently it streams videos from disk, so may work slow when playing many videos simultaneously.
It supports MP4.

It requires Windows and **ofxWMFVideoPlayer** addon.

## ofxUniversalMediaVideoHAP class

**ofxUniversalMediaVideoHAP** class uses ofxHapPlayer; it's super fast because uses HAP codec, intended for GPU efficience video playing.
For using it you must to encode your videos to HAP format.

It requires **ofxHapPlayer** addon for HAP support.
