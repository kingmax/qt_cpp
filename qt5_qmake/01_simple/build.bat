rem 在当前目录下运行qtenv2.bat, 		初始化Qt环境	(都需要先加入PATH)
rem 接着运行vcvarsall.bat x86_amd64, 	初始化VC环境
rem qmake -project QT+=widgets  		生成.pro项目文件 (会有问题：Project ERROR: Cannot run compiler 'cl'. Output:)
rem echo QT+=widgets >> 01_simple.pro   在最后插一句
rem 从vs2019/扩展/Qt VS Tools/打开.pro项目文件
rem 编译, 完成

pushd .
qtenv2.bat && vcvarsall.bat x86_amd64

popd

qmake -project 
echo QT+=widgets >> 01_simple.pro

