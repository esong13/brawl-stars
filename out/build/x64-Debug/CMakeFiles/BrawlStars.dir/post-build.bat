@echo off
cd /D C:\BrawlStars\BrawlStars\out\build\x64-Debug || (set FAIL_LINE=2& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different C:/BrawlStars/BrawlStars/cocos2d/external/openssl/prebuilt/win32/libssl-1_1.dll C:/BrawlStars/BrawlStars/out/build/x64-Debug/bin/BrawlStars/libssl-1_1.dll || (set FAIL_LINE=3& goto :ABORT)
cd /D C:\BrawlStars\BrawlStars\out\build\x64-Debug || (set FAIL_LINE=4& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different C:/BrawlStars/BrawlStars/cocos2d/external/openssl/prebuilt/win32/libcrypto-1_1.dll C:/BrawlStars/BrawlStars/out/build/x64-Debug/bin/BrawlStars/libcrypto-1_1.dll || (set FAIL_LINE=5& goto :ABORT)
cd /D C:\BrawlStars\BrawlStars\out\build\x64-Debug || (set FAIL_LINE=6& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different C:/BrawlStars/BrawlStars/cocos2d/external/uv/prebuilt/win32/uv.dll C:/BrawlStars/BrawlStars/out/build/x64-Debug/bin/BrawlStars/uv.dll || (set FAIL_LINE=7& goto :ABORT)
cd /D C:\BrawlStars\BrawlStars\out\build\x64-Debug || (set FAIL_LINE=8& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different C:/BrawlStars/BrawlStars/cocos2d/external/websockets/prebuilt/win32/websockets.dll C:/BrawlStars/BrawlStars/out/build/x64-Debug/bin/BrawlStars/websockets.dll || (set FAIL_LINE=9& goto :ABORT)
cd /D C:\BrawlStars\BrawlStars\out\build\x64-Debug || (set FAIL_LINE=10& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different C:/BrawlStars/BrawlStars/cocos2d/external/curl/prebuilt/win32/libcurl.dll C:/BrawlStars/BrawlStars/out/build/x64-Debug/bin/BrawlStars/libcurl.dll || (set FAIL_LINE=11& goto :ABORT)
cd /D C:\BrawlStars\BrawlStars\out\build\x64-Debug || (set FAIL_LINE=12& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different C:/BrawlStars/BrawlStars/cocos2d/external/win32-specific/gles/prebuilt/glew32.dll C:/BrawlStars/BrawlStars/out/build/x64-Debug/bin/BrawlStars/glew32.dll || (set FAIL_LINE=13& goto :ABORT)
cd /D C:\BrawlStars\BrawlStars\out\build\x64-Debug || (set FAIL_LINE=14& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different C:/BrawlStars/BrawlStars/cocos2d/external/win32-specific/icon/prebuilt/iconv.dll C:/BrawlStars/BrawlStars/out/build/x64-Debug/bin/BrawlStars/iconv.dll || (set FAIL_LINE=15& goto :ABORT)
cd /D C:\BrawlStars\BrawlStars\out\build\x64-Debug || (set FAIL_LINE=16& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different C:/BrawlStars/BrawlStars/cocos2d/external/win32-specific/MP3Decoder/prebuilt/libmpg123.dll C:/BrawlStars/BrawlStars/out/build/x64-Debug/bin/BrawlStars/libmpg123.dll || (set FAIL_LINE=17& goto :ABORT)
cd /D C:\BrawlStars\BrawlStars\out\build\x64-Debug || (set FAIL_LINE=18& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different C:/BrawlStars/BrawlStars/cocos2d/external/win32-specific/OggDecoder/prebuilt/libogg.dll C:/BrawlStars/BrawlStars/out/build/x64-Debug/bin/BrawlStars/libogg.dll || (set FAIL_LINE=19& goto :ABORT)
cd /D C:\BrawlStars\BrawlStars\out\build\x64-Debug || (set FAIL_LINE=20& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different C:/BrawlStars/BrawlStars/cocos2d/external/win32-specific/OggDecoder/prebuilt/libvorbis.dll C:/BrawlStars/BrawlStars/out/build/x64-Debug/bin/BrawlStars/libvorbis.dll || (set FAIL_LINE=21& goto :ABORT)
cd /D C:\BrawlStars\BrawlStars\out\build\x64-Debug || (set FAIL_LINE=22& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different C:/BrawlStars/BrawlStars/cocos2d/external/win32-specific/OggDecoder/prebuilt/libvorbisfile.dll C:/BrawlStars/BrawlStars/out/build/x64-Debug/bin/BrawlStars/libvorbisfile.dll || (set FAIL_LINE=23& goto :ABORT)
cd /D C:\BrawlStars\BrawlStars\out\build\x64-Debug || (set FAIL_LINE=24& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different C:/BrawlStars/BrawlStars/cocos2d/external/win32-specific/OpenalSoft/prebuilt/OpenAL32.dll C:/BrawlStars/BrawlStars/out/build/x64-Debug/bin/BrawlStars/OpenAL32.dll || (set FAIL_LINE=25& goto :ABORT)
cd /D C:\BrawlStars\BrawlStars\out\build\x64-Debug || (set FAIL_LINE=26& goto :ABORT)
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E copy_if_different C:/BrawlStars/BrawlStars/cocos2d/external/zlib/../win32-specific/zlib/prebuilt/zlib1.dll C:/BrawlStars/BrawlStars/out/build/x64-Debug/bin/BrawlStars/zlib1.dll || (set FAIL_LINE=27& goto :ABORT)
goto :EOF

:ABORT
set ERROR_CODE=%ERRORLEVEL%
echo Batch file failed at line %FAIL_LINE% with errorcode %ERRORLEVEL%
exit /b %ERROR_CODE%