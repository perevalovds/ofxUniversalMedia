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
* **ofxUniversalMediaImage** - images decoding with oF standard method using FreeImage,
* **ofxUniversalMediaImageTurgoJpeg** - JPEG images decoding with TurboJpeg,
* **ofxUniversalMediaVideo** - video player using DirectShow in Windows and others - related to oF standard ofVideoPlayer class,
* **ofxUniversalMediaVideoWMF** - video player using WFM (Windows),
* **ofxUniversalMediaVideoHAP** - video player using HAP codec.

Also, you can use this classes directly.


Below is some recommendations about choosing the appropriate class method for your needs.

## ofxUniversalMediaImage class

**ofxUniversalMediaImage** class works with images using ofTexture class; it's based on FreeImage for reading and decoding images on CPU.
It's universal. You can store decoded images in GPU, but it consumes much of memory.
You can store encoded images in CPU, but it not super-fast decoded.
Note, **ofxUniversalMediaImageTurgoJpeg** is faster when working with JPEGs, so use it if you work with JPEGs.

It's appropriate for using as video player, but you must to encode your videos to image sequences, without audio.


## ofxUniversalMediaImageTurgoJpeg class

**ofxUniversalMediaImageTurgoJpeg** class utilizes ofxTurboJpeg addon for reading and decoding JPEG images;
it's based on ofxTurboJpeg and decodes JPEGS very fast compared with ofxUniversalMediaImage,
so if you are using JPEG image sequences, in any case it's better choise that **ofxUniversalMediaImage**.

It's appropriate for using as video player, but you must to encode your videos to JPEG image sequences, without audio.

It requires **ofxTurboJpeg** addon.

## ofxUniversalMediaVideo class

**ofxUniversalMediaVideo** class utilizes standard **ofVideoPlayer** class.
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

**NOTE**: Player's constructor must work after oF app is started, because player requires initialized OpenGL to work.
So, don't declare player object "ofxUniversalMediaVideoWMF video;" as a global variable.
	Instead, declare it as a member of ofApp class (or it's member), 
	or define it as a pointer and use "video = new ofxWMFVideoPlayer()".

## ofxUniversalMediaVideoHAP class

**ofxUniversalMediaVideoHAP** class uses ofxHapPlayer; it's super fast because uses HAP codec, intended for GPU efficience video playing.
For using it you must to encode your videos to HAP format.

It requires **ofxHapPlayer** addon for HAP support.
