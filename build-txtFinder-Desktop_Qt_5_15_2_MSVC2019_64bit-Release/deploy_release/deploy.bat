md deploy
cd deploy
copy /y ..\txtFinder.exe txtFinder.exe
windeployqt txtFinder.exe
cd ..