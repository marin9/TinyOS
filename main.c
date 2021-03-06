#include "rpi.h"
#include "dev.h"
#include "lib.h"
#include "os.h"




 /*
static void t0() {
    while (1) {
        uart_print("Task 100\r\n");
        task_sleep(100);
    }
}

static void t1() {
    while (1) {
        uart_print("Task   300\r\n");
        task_sleep(300);
    }
}

static void t2() {
    while (1) {
        uart_print("Task     1000\r\n");
        task_sleep(1000);
    }
}

static void t3() {
    while (1) {
        uart_print("Task         1900\r\n");
        task_sleep(1900);
    }
}

void test1() {
    task_create(t0, 0, 0);
    task_create(t1, 0, 0);
    task_create(t2, 0, 0);
    task_create(t3, 0, 0);
}
 */

/*
static sem_t s;

static void tsk(void *arg) {
    int i;
    char *m = (char*)arg;

    while (1) {
        sem_wait(&s, 1);
        for (i = 0; i < 5; ++i) {
            uart_print(m);
            task_sleep(500);
        }
        sem_signal(&s);
        task_sleep(100);    
    }
}

void test2() {
    sem_init(&s, 1, 1);
    task_create(tsk, "A\r\n", 0);
    task_create(tsk, " B\r\n", 0);
    task_create(tsk, "  C\r\n", 0);
}
*/



void t0() {
    uart_print(" T0\r\n");
}

void t1() {
    uart_print("  T1\r\n");
}

void t2() {
    uart_print("   T2\r\n");
}

void t3() {
    uart_print("    T3\r\n");
}


void main() {
    pic_init();
    timer_init();
    uart_init(115200);
    i2c_init(400000);
    spi_init(100000);
    pwm_init(40000, 0x100);
    ssd1306_init();
    os_init();

    //os_start();


    tmr_init(0, 250, 1);
    tmr_init(1, 500, 1);
    tmr_init(2, 1000, 1);
    tmr_init(3, 2000, 1);

    tmr_attachintr(0, t0);
    tmr_attachintr(1, t1);
    tmr_attachintr(2, t2);
    tmr_attachintr(3, t3);

    tmr_start(0);
    tmr_start(1);
    tmr_start(2);
    tmr_start(3);

    while (1);


/*
    sspi init
    timer_delay(7*1000*1000);
    uart_print("Flash test\r\n");

    char buff[256];
    memset(buff, 0, 256);
    sspi_init(6, 13, 26);
    sspi_setbaud(1000000);
    sspi_ssinit(19);
    timer_delay(1000000);
*/
/*
    //sspi write
    sspi_start(19);
    sspi_send_byte(0x06);
    sspi_stop(19);
    timer_delay(1000000);


    sspi_start(19);
    sspi_send_byte(0x02);
    sspi_send_byte(0x00);
    sspi_send_byte(0x00);
    sspi_send_byte(0x00);

    sspi_send_byte('O');
    sspi_send_byte('K');
    sspi_send_byte(0x00);
    sspi_stop(19);
    timer_delay(1000000);

*/

/*
    sspi read
    sspi_start(19);
    sspi_send_byte(0x03);
    sspi_send_byte(0x00);
    sspi_send_byte(0x00);
    sspi_send_byte(0x00);

    int i;
    for (i = 0; i < 128; ++i)
        uart_putc(sspi_recv_byte());

    sspi_stop(19);
*/

}

