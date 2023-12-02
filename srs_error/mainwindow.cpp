#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "srs_kernel_error.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setbuf(stdout,nullptr);

    srs_error_t err = srs_error_new(ERROR_SOCKET_CREATE, "name=%s,age=%d","chw",18);
    printf("srs_error_desc=%s\n",srs_error_desc(err).c_str());
    printf("srs_error_summary=%s\n",srs_error_summary(err).c_str());
    printf("srs_error_code_str=%s\n",srs_error_code_str(err).c_str());
    printf("srs_error_code_longstr=%s\n",srs_error_code_longstr(err).c_str());

    srs_error_t err2 = srs_error_wrap(err,"add err!");
    printf("srs_error_desc2=%s\n",srs_error_desc(err2).c_str());

    printf("\nsrs_assert:\n");
    srs_assert(0);
}
//打印：
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
MainWindow::~MainWindow()
{
    delete ui;
}

