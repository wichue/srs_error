C++音视频流媒体服务器SRS源码框架解读，错误类(SrsCplxError)的使用.

SRS错误处理模块

SRS定义了一个功能强大的错误类(SrsCplxError)，可自定义错误码、错误描述、详细信息、摘要，错误发生的文件名、函数名、行号；可建立连接多个错误类的单链表，形成一个错误栈；为上述功能提供了接口宏。

此外，还自定义了断言宏(srs_assert)，在crash时使用backtrace打印回溯调用栈，方便排查bug。

//打印示例：

/**
 * srs_error_desc=code=1000(SocketCreate)(Create socket fd failed) : name=chw,age=18
 * thread [10993][create]: MainWindow() [../srs_error/mainwindow.cpp:13][errno=2]
 * srs_error_summary=code=1000(SocketCreate) : name=chw,age=18
 * srs_error_code_str=SocketCreate
 * srs_error_code_longstr=Create socket fd failed
 * srs_error_desc2=code=1000(SocketCreate)(Create socket fd failed) : add err! : name=chw,age=18
 * thread [10993][wrap]: MainWindow() [../srs_error/mainwindow.cpp:19][errno=2]
 * thread [10993][create]: MainWindow() [../srs_error/mainwindow.cpp:13][errno=2]
 *
 * srs_assert:
 * backtrace 5 frames of srs_error RTMP_SIG_SRS_SERVER
 * #0 0x71f4 1 0x00000000000071f3: SrsCplxError::srs_assert(bool) 于 srs_kernel_error.cpp:388
 * #1 0x4e5d 1 0x0000000000004e5c: MainWindow::MainWindow(QWidget*) 于 mainwindow.cpp:23
 * #2 0x4b66 1 0x0000000000004b65: main 于 main.cpp:8
 * #3 0x240b3 0 /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf3) [0x7fa8a0e8c0b3]
 * #4 0x4a5e 0 /home/chuwei/chw/srs_test/srs_git/srs_error/build-srs_error-Desktop_Qt_5_14_2_GCC_64bit-Debug/bin/srs_error(+0x4a5e) [0x5602d73b7a5e]
 * srs_error: ../srs_error/srs/srs_kernel_error.cpp:407：static void SrsCplxError::srs_assert(bool): 假设 ‘expression’ 失败。
 */
