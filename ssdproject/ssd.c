// SSD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    // for(int i=0;i<argc;i++){
    //     printf("%s\n",argv[i]);

    // }
    
    // argc_argv 갯수
    //    0   1 -> read write

    // 최소 공간 사이즈 4byte
    // LBA 0 ~ 99 총 100개 -> 400byte

    // Read, Write, Unmap(delete)
    // exit help fullwrite fullread

    // 파일 읽고 가져오기
    char path_d[100] = "./nand.txt";
    FILE *fStream_r;
    FILE *fStream_w;

    FILE *fres;
    char path_r[100] = "./result.txt";
    

    fStream_r = fopen(path_d, "r");

    // char buffer[801] = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    char buffer[801];
    char arr[100][9];

    if (fStream_r)
    {
        fread(buffer, 1, 801, fStream_r);
        // 없다면
        // memset(buffer, '0', sizeof(buffer));
        // fwrite(buffer, 800, 1, fStream_w);
        int temm = 0;
        for (int i = 99; i >= 0; i--)
        {
            for (int j = 7; j >= 0; j--)
            {
                // printf("%c\n", buffer[temm]);
                arr[i][j] = buffer[temm++];
            }
            arr[i][8] = '\0';
        }

        fclose(fStream_r);
        // 다저장 시켰고

        // 이게 처음에할 작업이고

        int tmp = 0;
        // tmp = atoi(argv[2]); //오류날수도
        tmp = atoi(argv[2]);
       // printf("tmp: %d\n",tmp);
        if (!strcmp(argv[1], "W"))
        {
            fStream_w = fopen(path_d, "w");

            if (fStream_w)
            {
                char ctmp[10];
                char abuf[802];
                strcpy(ctmp, argv[3]);
                //printf("%s\n", ctmp);
                for (int i = 0; i < 8; i++)
                {
                    arr[tmp][i] = ctmp[i + 2];
                }

                int temm2=0;
                for (int i = 99; i >= 0; i--)
                {
                    for (int j = 7; j >= 0; j--)
                    {
                        // printf("%c\n", buffer[temm]);
                        abuf[temm2++]=arr[i][j] ;
                    }
                }
                abuf[800] = '\0';
                fputs(abuf, fStream_w);
                fclose(fStream_w);
            }
        }
        else if (!strcmp(argv[1], "R"))
        {
           // printf("R 비교 elif문 시작\n");
            // result에 넣기
            fres = fopen(path_r, "w");
            if (fres)
            {
               // printf("R fres elif문 시작\n");
                char abuf[11];
                abuf[0] = '0';
                abuf[1] = 'x';
                for (int ij = 0; ij < 8; ij++)
                {
                    abuf[ij + 2] = arr[tmp][ij];
                }
                abuf[10] = '\0';
                printf("%s\n",abuf);
                fputs(abuf, fres);
            }
            fclose(fres);
        }
        else
        {
        }
    }
    else
    { // 실패}
    }
    

    
    return 0;
}
