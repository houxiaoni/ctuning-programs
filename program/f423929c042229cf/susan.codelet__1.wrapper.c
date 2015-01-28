/* 
 Codelet from MILEPOST project: http://cTuning.org/project-milepost
 Updated by Grigori Fursin to work with Collective Mind Framework

 3 "./susan.codelet__1.wrapper.c" 3 4
*/

#include <stdio.h>

int __astex_write_message(const char * format, ...);
int __astex_write_output(const char * format, ...);
void __astex_exit_on_error(const char * msg, int code, const char * additional_msg);
void * __astex_fopen(const char * name, const char * mode);
void * __astex_memalloc(long bytes);
void __astex_close_file(void * file);
void __astex_read_from_file(void * dest, long bytes, void * file);
int __astex_getenv_int(const char * var);
void * __astex_start_measure();
double __astex_stop_measure(void * _before);
typedef int  TOTAL_TYPE;
typedef unsigned char  uchar;
void  astex_codelet__1(int increment, int mask_size, int area, int __astex_addr__tmp[1], uchar *ip, uchar *dpt, uchar *cp, TOTAL_TYPE __astex_addr__total[1]);
int main(int argc, const char **argv)
{
  int  increment = 599;
  int  mask_size = 7;
  int  area = 0;
  int  *__astex_addr__tmp;
  uchar  *ip;
  uchar  *dpt;
  uchar  *cp;
  TOTAL_TYPE  *__astex_addr__total;
  void * codelet_data_file_descriptor = (void *) 0;

#ifdef OPENME
  openme_init(NULL,NULL,NULL,0);
  openme_callback("PROGRAM_START", NULL);
#endif

  if (argc < 2)
    __astex_exit_on_error("Please specify data file in command-line.", 1, argv[0]);
  codelet_data_file_descriptor = __astex_fopen(argv[1], "rb");
  
  char * __astex_addr__tmp__region_buffer = (char *) __astex_memalloc(4);
  __astex_write_message("Reading __astex_addr__tmp value from %s\n", argv[1]);
  __astex_read_from_file(__astex_addr__tmp__region_buffer, 4, codelet_data_file_descriptor);
  __astex_addr__tmp = (int *) (__astex_addr__tmp__region_buffer + 0l);
  char * ip__region_buffer = (char *) __astex_memalloc(284896);
  __astex_write_message("Reading ip value from %s\n", argv[1]);
  __astex_read_from_file(ip__region_buffer, 284896, codelet_data_file_descriptor);
  ip = (uchar *) (ip__region_buffer + 0l);
  char * dpt__region_buffer = (char *) __astex_memalloc(225);
  __astex_write_message("Reading dpt value from %s\n", argv[1]);
  __astex_read_from_file(dpt__region_buffer, 225, codelet_data_file_descriptor);
  dpt = (uchar *) (dpt__region_buffer + 0l);
  char * cp__region_buffer = (char *) __astex_memalloc(516);
  __astex_write_message("Reading cp value from %s\n", argv[1]);
  __astex_read_from_file(cp__region_buffer, 516, codelet_data_file_descriptor);
  cp = (uchar *) (cp__region_buffer + 436l);
  char * __astex_addr__total__region_buffer = (char *) __astex_memalloc(4);
  __astex_write_message("Reading __astex_addr__total value from %s\n", argv[1]);
  __astex_read_from_file(__astex_addr__total__region_buffer, 4, codelet_data_file_descriptor);
  __astex_addr__total = (TOTAL_TYPE *) (__astex_addr__total__region_buffer + 0l);
  void * _astex_timeval_before = __astex_start_measure();
  int _astex_wrap_loop = __astex_getenv_int("CT_REPEAT_MAIN");
  if (! _astex_wrap_loop)
    _astex_wrap_loop = 1;

#ifdef OPENME
  openme_callback("KERNEL_START", NULL);
#endif

  while (_astex_wrap_loop > 0)
  {
    --_astex_wrap_loop;
  astex_codelet__1(increment, mask_size, area, __astex_addr__tmp, ip, dpt, cp, __astex_addr__total);

  }

#ifdef OPENME
  openme_callback("KERNEL_END", NULL);
#endif

  __astex_write_output("Total time: %lf\n", __astex_stop_measure(_astex_timeval_before));


#ifdef OPENME
  openme_callback("PROGRAM_END", NULL);
#endif

  return 0;
}

