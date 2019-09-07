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
* **ofxUniversalMediaImage** - image and image sequence supporting any image formats, decoding with oF standard method using FreeImage,
* **ofxUniversalMediaImageTurgoJpeg** - image and image sequence supporting JPEG images decoding with TurboJpeg,
* **ofxUniversalMediaVideo** - video player using DirectShow in Windows and others - related to oF standard ofVideoPlayer class,
* **ofxUniversalMediaVideoWMF** - video player using WFM (Windows),
* **ofxUniversalMediaVideoHap** - video player using HAP/HAPQ codec.

Also, you can use this classes directly.


Below is some recommendations about choosing the appropriate class method for your needs.

## ofxUniversalMediaImage class

**ofxUniversalMediaImage** class works with images using ofTexture class; it's based on FreeImage for reading and decoding images on CPU.
It's universal. You can store decoded images in GPU, but it consumes much of memory.
You can store encoded images in CPU, but it not super-fast decoded.
Note, **ofxUniversalMediaImageTurgoJpeg** is faster when working with JPEGs, so use it if you work with JPEGs.
But JPEG doesn't support alpha-channel, so for sequences with alpha-channel you need to use **ofxUniversalMediaImage**.

It's appropriate for using as video player, but you must to encode your videos to image sequences, without audio.


## ofxUniversalMediaImageTurgoJpeg class

**ofxUniversalMediaImageTurgoJpeg** class utilizes ofxTurboJpeg addon for reading and decoding JPEG images;
it's based on ofxTurboJpeg and decodes JPEGS very fast compared with ofxUniversalMediaImage,
so if you are using JPEG image sequences, in any case it's better choise that **ofxUniversalMediaImage**.
But JPEG doesn't support alpha-channel, so for sequences with alpha-channel you need to use **ofxUniversalMediaImage**.

It's appropriate for using as video player, but you must to encode your videos to JPEG image sequences, without audio.

Requirements: **ofxTurboJpeg** addon (I tested it on my fork of the addon).

## ofxUniversalMediaVideo class

**ofxUniversalMediaVideo** class utilizes standard **ofVideoPlayer** class.
In Windows, it uses DirectShow method and loads all video to CPU, so loops work smoothly.
Also, it CPU-intensive. It supports MPG4 (after installing K-lite codecs pack).

Requirements: **K-Lite** codecs pack for playing MPG4 videos.

## ofxUniversalMediaVideoWMF class

**ofxUniversalMediaVideoWMF** class uses ofWMFVideoPlayer addon; it's based on Windows Media Foundation API,
so it gives fast and smooth playing because it's modern Windows method for playing videos using GPU, when available. 

It's current oF impementation is not super perfect, and as a result, it's not very well syncing and not good for looping videos
(seems it skips the last frame and sometimes freeze and drop frames). 
Also, currently it streams videos from disk, so may work slow when playing many videos simultaneously.
But, it works on GPU and fits well for situations when syncing is not so important.
It supports MP4.

Requirements: Windows OS and **ofxWMFVideoPlayer** addon (I tested it on my fork of the addon).

**NOTE**: Player's constructor must work after oF app is started, because player requires initialized OpenGL to work.
So, don't declare player object "ofxUniversalMediaVideoWMF video;" as a global variable.
	Instead, declare it as a member of ofApp class (or it's member), 
	or define it as a pointer and use "video = new ofxWMFVideoPlayer()".

## ofxUniversalMediaVideoHAP class

**ofxUniversalMediaVideoHap** class uses ofxHapPlayer; it's allows to work with very big image sizes 
and is super fast because uses HAP (currently HAPQ - see note) codec, 
intended for GPU efficience video playing.
For using it you must to encode your videos to HAP (currently HAPQ) format.

HAP files are huge, so it's proposed to use them with SSD drives.

Requirements: **ofxHapPlayer** addon for HAP support (I tested it on my fork of the addon).

For encoding your videos to HAP/HAPQ, you can get HAP codec for Windows and Mac OS at "hap-qt-codec" repo or in my fork of **ofxHapPlayer** addon.

**NOTE**: currently ofxUniversalMediaVideoHAP supports HAPQ codec (not HAP), because it gets better image quality.
Remember, that drawing HAPQ requires passing via ofxHapPlayer's shader, so
in the class it's enabled at each draw() automatically by default.
Hence, if you need to pass it via your own shader, at the first draw to FBO

