#include <QCoreApplication>
#include <iostream>
#include <stdio.h>
#include <getopt.h>
#include <motortest.h>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MotorTest motor;
    static int verbose_flag;
    int index;
    int c;
    char help[] = "gunakan: motor -g untuk memajukan motor\n-m\t--mundur\t\tuntuk memundurkan motor\n-l\t--kiri\t\t\tnyalakan motor kiri saja\n-r\t--kanan \tnyalakan motor kanan saja\n";
    opterr = 0;
    static struct option long_options[] =
    {
         {"verbose", no_argument,       &verbose_flag, 1},
         {"brief",   no_argument,       &verbose_flag, 0},
         {"maju",     no_argument,       0, 'g'},
         {"mundur",     no_argument,       0, 'm'},
         {"kiri",  no_argument,       0, 'l'},
         {"kanan",  no_argument,       0, 'r'},
         {"help",  no_argument,       0, 'h'},
         {"stop",  no_argument,       0, 'q'},
         {"unexport", no_argument,    0, 'u'},
         {0, 0, 0, 0}
   };

   int option_index = 0;

   while ((c = getopt_long (argc, argv, "hm:l:gr:",long_options,&option_index)) != -1){
       switch (c) {
       case NULL:
          //motor.no_ARG();
           break;
       case 'q':
           motor.stop();
           break;
       case 'u':
           motor.kembalikanData();
           break;
       case 'g':
           motor.motorMaju();
           break;

       case 'm':
           motor.motorMundur();
           break;

       case 'r':
           motor.motorKanan();
           break;

       case 'l':
           motor.motorKiri();
           break;

       case 'h':
           printf("%s\n",help);
           exit(0);
           break;
       case '?':
           if(optopt == 'c')
               fprintf (stderr, "Pilihan -%c requires an argument.\n", optopt);

           else if (isprint (optopt))
               fprintf (stderr, "Tidak ada pilihan `-%c'.\n\ngunakan: motor -g untuk memajukan motor\n-m\t--mundur\t\tuntuk memundurkan motor\n-l\t--kiri\t\t\tnyalakan motor kiri saja\n-r\t--kanan \tnyalakan motor kanan saja\n", optopt);

           else
               fprintf (stderr,
                        "Tidak ada karakter itu `\\x%x'.\n" ,optopt);

           return 1;
       default:
           abort();
           break;
       }
   }


   for (index = optind; index < argc; index++){
          printf ("Argumen yang Dipilih tidak ada %s\n", argv[index]);
   }


    return a.exec();
}
