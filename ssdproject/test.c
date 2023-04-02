//test
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void m_write(char buf1[256],char buf2[256]){
          //buf 1 3    buf 0x AAAADDDD
    char m_command[256];
    strcpy(m_command,"./ssd W ");
    strcat(m_command,buf1);
    strcat(m_command," ");
    strcat(m_command,buf2);
    int ret=system(m_command);
    printf("%s\n",m_command);
}

void m_read(char buf1[256]){
    char m_command[256];
//   printf("%s\n",buf1);
    //strcat(tem_path,"");
    strcpy(m_command,"./ssd R ");
    strcat(m_command,buf1);
    
//   printf("%s\n",m_command);
    int ret=system(m_command);
}


int main(int argc, char *argv[]){
    int ret;
    char m_command[256];
   //ret=system(m_command);
    char cmd0[256];
    char cmd1[256];
    char cmd2[256];
    
    char ssd_path[256]="";
    printf("program start!\n");
    while(1){

        //종료 조건
       // char tem_path[256]=system("pwd");
        //동작
        scanf("%s",cmd0);
        if(!strcmp(cmd0,"write")){
            scanf("%s %s",cmd1,cmd2);
            m_write(cmd1,cmd2);

            printf("write success!\n");
        }else if(!strcmp(cmd0,"read")){
            char buf1 [256];
            scanf("%s",buf1);
            m_read(buf1);
            printf("read success!\n");
        }else if(!strcmp(cmd0,"exit")){
            //nand.txt에 저장 필요
            return 0;
            
        }else if(!strcmp(cmd0,"help")){
            //각 명령어당 사용방법을 출력한다
            printf("1. write n address(0xdddddddd)\n");
            printf("2. read n\n");
            printf("3. exit\n");
            printf("4. help\n");
            printf("5. fullwrite address(0xdddddddd)\n");
            printf("6. fullread\n");
            
        }else if(!strcmp(cmd0,"fullwrite")){
            scanf("%s",cmd2);
            //nand.txt에 다 적어주기 100번 돌면서
            char buf0[256];
            for(int i=0;i<100;i++){
                sprintf(buf0,"%d",i);
                m_write(buf0,cmd2);
            }
            
        }else if(!strcmp(cmd0,"fullread")){
            //result.txt 100번 읽어오기
            char buf0[256];
            for(int i=0;i<100;i++){
                sprintf(buf0,"%d",i);
                m_read(buf0);
            }
            printf("fullread success!\n");
        }else{
                //제대로 입력
            printf("INVALID COMMAND\n");
        }
    }

    return 0;
}