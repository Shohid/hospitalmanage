#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
char s[1000],s1[1000],s2[1000],s3[1000],s4[1000];
void pain();
long long int gid()
{
    long long int x;
    FILE *fp;
    fp=fopen("sid.dat","r");
    fscanf(fp,"%lld",&x);
    fclose(fp);
    return x;

}
void sid(long long int x)
{
    FILE *fp;
    fp=fopen("sid.dat","w");
    fprintf(fp,"%lld",x);
    fclose(fp);
}
void geth();
void update();
void med();
void doc();
void exit();
void store();
long long int j,k,l,m,n,o,p;
COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void era(int x,int y)
{
    int i;
    gotoxy(x,y);
    for(i=0; i<=80; i++)
        printf(" ");
    gotoxy(x,y);
}
void lbox()
{
    int i;
    gotoxy(25,6);
    printf("%c",201);
    for(i=26; i<55; i++)
    {
        gotoxy(i,6);
        printf("%c",205);
    }
    gotoxy(55,6);
    printf("%c",187);
    gotoxy(25,6);
    for(i=6; i<8; i++)
    {
        gotoxy(25,i+1);
        printf("%c",186);
    }
    gotoxy(25,9);
    printf("%c",200);
    for(i=26; i<55; i++)
    {
        gotoxy(i,9);
        printf("%c",205);
    }
    gotoxy(55,9);
    printf("%c",188);
    gotoxy(55,6);
    for(i=6; i<8; i++)
    {
        gotoxy(55,i+1);
        printf("%c",186);
    }

}
void box1()
{
    int i;
    gotoxy(1,3);
    printf("%c",201);
    for(i=1; i<79; i++)
    {
        gotoxy(1+i,3);
        printf("%c",205);
    }
    gotoxy(80,3);
    printf("%c",187);
    gotoxy(1,3);
    for(i=4; i<8; i++)
    {
        gotoxy(1,i);
        printf("%c",186);
    }
    gotoxy(1,9);
    for(i=4; i<8; i++)
    {
        gotoxy(80,i);
        printf("%c",186);
    }
    gotoxy(80,7);
    printf("%c",188);
    gotoxy(1,7);
    printf("%c",200);
    for(i=1; i<79; i++)
    {
        gotoxy(1+i,7);
        printf("%c",205);
    }
}

void box()
{
    int i;
    for(i=3; i<=79; i++)
    {
        gotoxy(i,3);
        printf("%c",219);
        gotoxy(78,45);
        printf("%c",219);
        gotoxy(i,45);
        printf("%c",219);
    }

    for(i=3; i<=45; i++)
    {
        gotoxy(3,i);
        printf("%c",219);
        gotoxy(79,i);
        printf("%c",219);
    }
}
void wbox()
{
    int i;
    for(i=5; i<=75; i++)
    {
        gotoxy(i,5);
        printf("%c",219);
        gotoxy(74,40);
        printf("%c",219);
        gotoxy(i,40);
        printf("%c",219);
    }

    for(i=5; i<=40; i++)
    {
        gotoxy(5,i);
        printf("%c",219);
        gotoxy(75,i);
        printf("%c",219);
    }
}

void ani()
{
    int i;
    for (i=55; i>=27; i--)
    {
        Sleep(20);
        gotoxy(i,5);
    }
    for (i=27; i<=55; i++)
    {
        Sleep(20);
        gotoxy(i,5);
    }
}
int t(int x,int y)
{
    time_t t = time(0);
    struct tm * now = localtime( & t );
    gotoxy(x,y);
    printf("Date: %d-%d-%d ",now->tm_mday,now->tm_mon+1,now->tm_year-100);
    gotoxy(x,y+2);
    printf("Time: %d:%d",now->tm_hour, now->tm_min);
    return 0;
}
long long int D()
{
    time_t t = time(0);
    struct tm * now = localtime( & t );
    return ((now->tm_mday*100+(now->tm_mon+1))*100+(now->tm_year-100));
}
void mbox()
{
    int i;
    gotoxy(1,8);
    printf("%c",201);
    for(i=1; i<79; i++)
    {
        gotoxy(1+i,8);
        printf("%c",205);
    }

    gotoxy(80,8);
    printf("%c",187);
    gotoxy(1,8);
    for(i=6; i<30; i++)
    {
        gotoxy(1,2+i);
        printf("%c",186);
    }
    gotoxy(1,32);
    printf("%c",200);
    for(i=1; i<79; i++)
    {
        gotoxy(1+i,32);
        printf("%c",205);
    }
    gotoxy(80,32);
    printf("%c",188);
    gotoxy(80,6);
    for(i=6; i<30; i++)
    {
        gotoxy(80,2+i);
        printf("%c",186);
    }
}
void mmenu()
{
    system("cls");
    gotoxy(27,5);
    printf("WELCOME TO HOSPITAL MANAGEMENT");
f:
    gotoxy(22,8);
    printf("...PLEASE CHOOSE FROM THE MENU BELOW...");
//    gotoxy(22,9);
//    printf("PLEASE PRESS FIRST LETTER ONLY");
    t(65,22);
    gotoxy(14,15);
    printf("ARE YOU NEW HERE?? Y/N");
    gotoxy(14,17);
//    printf("UPDATE INFORMATION");
//    gotoxy(14,19);
    printf("EXIT");
    gotoxy(10,25);
    printf("(PLEASE PRESS FIRST LETTER ONLY)");
    char ch;
    gotoxy(10,26);
    ch=getche();
    switch(toupper(ch))
    {
        era(10,26);
//    case 'U':
//        era(10,26);
//        update();
//        break;
    case 'Y':
        era(10,26);
        geth();
        break;
    case 'E':
        era(10,26);
        gotoxy(10,25);
        printf("ARE YOU SURE WANT TO EXIT ?? Y/N");
        ch=getche();
        era(10,25);
        if(toupper(ch)=='Y')
        {
            gotoxy(10,25);
            sid(j);
            break;
        }
        else

        {
            era(10,26);
            goto f;
        }
    case 'N':

    default:
        era(10,26);
        gotoxy(10,27);
        printf("PLEASE PRESS VALID CHARACHTERS ONLY (U,G,E)");
        Sleep(500);
        printf(".  ");
        Sleep(1000);
        printf(".  ");
        Sleep(1000);
        printf(".");
        Sleep(500);
        era(10,27);
        goto f;
    }
}
main()
{
    j=gid();
    char a,b[10000];
    FILE *fp;
    mmenu();
//    fp=fopen("new sayem.dat","a");
//    while(gets(b))
//    {
//        fputs(b,fp);
//        fputs("\n",fp);
//    }
//    fclose(fp);
//    fp=fopen("neew sayem.dat","r");
//    char c[121];
//    while(fscanf(fp,"%s",c)!=EOF)
//    {
//        puts(c);
//    }
//    fclose(fp);
}
void update()
{
    system("cls");
    gotoxy(27,5);
    printf("UPDATE INFO");
    gotoxy(10,15);
    printf("UPDATE MEDICINE INFO");
    gotoxy(10,17);
    printf("UPDATE DOCTOR INFO");
    gotoxy(10,19);
    printf("RETURN TO PREVIOUS MENU");
f2:
    gotoxy(10,25);
    printf("(PLEASE PRESS FIRST LETTER ONLY)");
    char ch;
    gotoxy(10,26);
    ch=getche();
    switch(toupper(ch))
    {
    case 'M':
        med();
        break;
    case 'D':
        doc();
        break;
    case 'R':
        mmenu();
        break;
    default:
        gotoxy(10,27);
        printf("PLEASE PRESS VALID CHARACHTERS ONLY (M,D,R)");
        Sleep(500);
        printf(".  ");
        Sleep(1000);
        printf(".  ");
        Sleep(1000);
        printf(".");
        Sleep(500);
        era(10,27);
        goto f2;
    }
}
void med()
{
    system("cls");
    gotoxy(30,5);
    printf("MEDICINE INFO UPDATE");
    gotoxy(23,8);
    printf("PLEASE USE \"_\" INSTEAD OF SPACEBAR");
    gotoxy(5,14);
    printf("MEDICINE COMPOSITION:");
    gotoxy(5,16);
    printf("MEDICINE COMMERCIAL NAME(S):");
    gotoxy(5,18);
    printf("(USE COMMA \",\" TO SEPERATE)");
    gotoxy(5,22);
    printf("NAME OF THE CURING DISEASE:");
    gotoxy(55,14);
    printf("DOSAGE:");
    gotoxy(52,15);
    printf("(Ex. 1+0+1)");
    char s1[10000],s2[200],s3[200],s4[200],c;
    gotoxy(27,14);
    int i=0;
    while(c=getche())
    {
        if(!isalpha(c)&&!isdigit(c)&&c!='+'&&c!=32)
            break;
        if(c==' ')
            s2[i]=' ';
        else
            s2[i]=toupper(c);
        i++;
    }
    i=0;
    gotoxy(34,16);
    i=0;
    while(c=getche())
    {
        if(!isalpha(c)&&!isdigit(c)&&c!='+'&&c!=32)
            break;
        if(c==' ')
            s3[i]=' ';
        else
            s3[i]=toupper(c);
        i++;
    }
    i=0;
    gotoxy(32,22);
    i=0;
    while(c=getche())
    {
        if(!isalpha(c)&&!isdigit(c)&&c!='+'&&c!=32)
            break;
        if(c==' ')
            s1[i]=' ';
        else
            s1[i]=toupper(c);
        i++;
    }
    i=0;
    gotoxy(62,14);
    i=0;
    while(c=getche())
    {
        if(!isalpha(c)&&!isdigit(c)&&c!='+'&&c!=32)
            break;
        if(c==' ')
            s4[i]=' ';
        else
            s4[i]=toupper(c);
        i++;
    }
    i=0;
    strcat(s1,"#");
    strcat(s2,"#");
    strcat(s3,"#");
    strcat(s4,"#");
    strcat(s1,s2);
    strcat(s1,s3);
    strcat(s1,s4);
    FILE *fp;
    fp=fopen("new shohid medicine.dat","a");
    fputs(s1,fp);
    fputs("\n",fp);
    fclose(fp);
    strcpy(s1,"");
    strcpy(s2,"");
    strcpy(s3,"");
    strcpy(s4,"");
    gotoxy(5,23);
    printf("MEDICINE SAVED SUCCESSFUL");
    gotoxy(5,24);
    printf("RETURN PREVIOUS MENU OR ADD MORE?");
f:
    gotoxy(5,25);
    c=toupper(getche());
    switch(c)
    {
    case 'R':
        update();
        break;
    case 'A':
        med();
        break;
    default:
        era(5,25);
        gotoxy(5,25);
        printf("PLEASE PRESS CORRECT CHARACTERS ONLY(R,A)");
        Sleep(500);
        printf(".  ");
        Sleep(1000);
        printf(".  ");
        Sleep(1000);
        printf(".");
        Sleep(500);
        era(5,25);
        goto f;
    }

}
void doc()
{
    system("cls");
    gotoxy(30,5);
    printf("DOCTOR'S INFO UPDATE");
    gotoxy(5,14);
    printf("ADD DOCTOR");
    gotoxy(5,16);
    printf("MODIFY DOCTOR");
    gotoxy(5,18);
    printf("RETURN TO PREVIOUS MENU");
    char ch;
    gotoxy(10,26);
f2:
    ch=getche();
    switch(toupper(ch))
    {
    case 'M':
        dmod();
        break;
    case 'A':
        dadd();
        break;
    case 'R':
        update();
    default:
        era(10,26);
        gotoxy(10,26);
        printf("PLEASE PRESS VALID CHARACHTERS ONLY (M,A,R)");
        Sleep(500);
        printf(".  ");
        Sleep(1000);
        printf(".  ");
        Sleep(1000);
        printf(".");
        Sleep(500);
        era(10,26);
        goto f2;
    }
    gotoxy(5,18);
    printf("(USE COMMA \",\" TO SEPERATE)");
    gotoxy(5,22);
    printf("NAME OF THE CURING DISEASE:");
    gotoxy(55,14);
    printf("DOSAGE:");
    gotoxy(52,15);
    printf("(Ex. 1+0+1)");
    getchar();
}
void dadd()
{
    system("cls");
    gotoxy(30,5);
    printf("ADD NEW DOCTOR");
    gotoxy(5,14);
    printf("DOCTOR NAME:");
    gotoxy(5,16);
    printf("SPECIALITY:");
    gotoxy(5,18);
    printf("CHAMBER ADDRESS:");
    gotoxy(5,20);
    printf("AVAILABLITY TIME:");
    gotoxy(5,22);
    printf("AVAILABLITY DAY(s):");
    char s1[10000],s2[200],s3[200],s4[200],s5[200];
    gotoxy(13,14);
    gets(s1);
    gotoxy(12,16);
    gets(s2);
    gotoxy(17,18);
    gets(s3);
    gotoxy(18,20);
    gets(s4);
    gotoxy(20,22);
    gets(s5);
    strcat(s1,"#");
    strcat(s2,"#");
    strcat(s3,"#");
    strcat(s4,"#");
    strcat(s5,"#");
    strcat(s1,s2);
    strcat(s1,s3);
    strcat(s1,s4);
    strcat(s1,s5);
    FILE *fp;
    fp=fopen("new sayem doctor.dat","a");
    fputs(s1,fp);
    fputs("\n",fp);
    fclose(fp);
    strcpy(s1,"");
    strcpy(s2,"");
    strcpy(s3,"");
    strcpy(s4,"");
    strcpy(s5,"");

}
void dmod()
{
    system("cls");
    gotoxy(30,5);
    printf("MODIFY DOCTOR");
    gotoxy(5,12);
    printf("PLEASE ENTER THE NAME OF THE DOCTOR TO BE MODYFIED:");
    char s[1000],s6[1000];
    gets(s);
    int x=strlen(s),y=0;
    FILE *fp;
    fp=fopen("new sayem doctor.dat","r");
    while(fscanf(fp,"%s",s6)!=EOF)
    {
        if(strncmp(s,s6,x)==0)
        {
            y++;
            break;
        }
    }
    fclose(fp);
    if(y!=0)
    {
        system("cls");
        gotoxy(30,5);
        printf("MODIFY DOCTOR");
        gotoxy(5,14);
        printf("DOCTOR NAME: %s",s);
        gotoxy(5,16);
        printf("SPECIALITY:");
        gotoxy(5,18);
        printf("CHAMBER ADDRESS:");
        gotoxy(5,20);
        printf("AVAILABLITY TIME:");
        gotoxy(5,22);
        printf("AVAILABLITY DAY(s):");
        char s1[10000],s2[200],s3[200],s4[200],s5[200];
        gotoxy(12,16);
        int i=0;
        while((s2[i]=getche())!="\n")
            i++;
        i=0;
        gotoxy(17,18);
        i=0;
        while((s3[i]=getche())!="\n")
            i++;
        i=0;
        gotoxy(18,20);
        i=0;
        while((s4[i]=getche())!="\n")
            i++;
        i=0;
        gotoxy(20,22);
        i=0;
        while((s5[i]=getche())!="\n")
            i++;
        i=0;
        strcat(s2,"#");
        strcat(s3,"#");
        strcat(s4,"#");
        strcat(s5,"#");
        strcat(s1,s);
        strcat(s1,s2);
        strcat(s1,s3);
        strcat(s1,s4);
        strcat(s1,s5);
        FILE *fp;
        fp=fopen("new shohid doctor.dat","a");
        fputs(s1,fp);
        fputs("\n",fp);
        fclose(fp);
        strcpy(s1,"");
        strcpy(s2,"");
        strcpy(s3,"");
        strcpy(s4,"");
        strcpy(s5,"");
    }
    else
    {
        printf("THE NAME NOT IN LISTED BEFORE");
    }
    getchar();
}
void geth()
{
    int i,k,l;
    system("cls");
    FILE *fp,*fp1,*fp2;
    gotoxy(0,2);
    fflush(stdin);
    gotoxy(5,4);
    char s5[100],s6[100],s7[100],s8[100],s9[100],s10[10],s11[10],c;
    printf("Please Enter The Following Informations");
    gotoxy(3,8);
    printf("Name: ");
    gotoxy(3,10);
    printf("Age: ");
    gotoxy(3,12);
    printf("Address: ");
    gotoxy(3,14);
    printf("Contact no.: ");
    gotoxy(3,16);
    printf("E-mail: ");
    gotoxy(10,8);
    gets(s);
    gotoxy(8,10);
    gets(s1);
    gotoxy(12,12);
    gets(s2);
    gotoxy(16,14);
    gets(s3);
    gotoxy(12,16);
    gets(s4);
    fflush(stdin);
ff:
    system("cls");
    gotoxy(10,3);
    printf("PLEASE PRESS FIRST LETTER OF YOUR DISEASE OR 'R' FOR RETURNING PREVIOUS MENU\n");
    gotoxy(10,5);
    printf("  **FEVER** **COLD** **GASTRIC** **PAIN** **WEEKNESS** **ANXIETY**\n");
    gotoxy(1,6);
    c=getche();
    era(1,5);
    switch(toupper(c))
    {
    case 'F':
        printf("Please Select a doctor from below: \n\n");
        fp1=fopen("Mdoc.dat","r");
        i=1;
        while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
        {
            printf("%d. %s %s %s %s\n",i,s5,s6,s7,s8);
            i++;
        }
        fclose(fp1);
        switch(c=getche())
        {
        case '1':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: FEVER\n");
            printf("MEDICINE: NAPA,NAPA EXTRA\n");
            printf("DOSAGE: 1+0+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
           fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld FEVER NAPA,NAPA EXTRA 1+0+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '2':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: FEVER\n");
            printf("MEDICINE: NAPA,NAPA EXTRA\n");
            printf("DOSAGE: 1+0+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
           fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld FEVER NAPA,NAPA EXTRA 1+0+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '3':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: FEVER\n");
            printf("MEDICINE: NAPA,NAPA EXTRA\n");
            printf("DOSAGE: 1+0+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld FEVER NAPA,NAPA EXTRA 1+0+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '4':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: FEVER\n");
            printf("MEDICINE: NAPA,NAPA EXTRA\n");
            printf("DOSAGE: 1+0+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld FEVER NAPA,NAPA EXTRA 1+0+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '5':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: FEVER\n");
            printf("MEDICINE: NAPA,NAPA EXTRA\n");
            printf("DOSAGE: 1+0+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld FEVER NAPA,NAPA EXTRA 1+0+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        }
        fclose(fp1);
        j++;
        break;
    case 'C':
        printf("Please Select a doctor from below: \n\n");
        fp1=fopen("Mdoc.dat","r");
        i=1;
        while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
        {
            printf("%d. %s %s %s %s\n",i,s5,s6,s7,s8);
            i++;
        }
        fclose(fp1);
        switch(c=getche())
        {
        case '1':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: COLD\n");
            printf("MEDICINE: HISTACINE\n");
            printf("DOSAGE: 1+0+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=0;
            int xx=c-48;
            printf("\t\t%d\n",xx);
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld COLD HISTACINE 1+1+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '2':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: COLD\n");
            printf("MEDICINE: HISTACINE\n");
            printf("DOSAGE: 1+0+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld COLD HISTACINE 1+1+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '3':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: COLD\n");
            printf("MEDICINE: HISTACINE\n");
            printf("DOSAGE: 1+0+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld COLD HISTACINE 1+1+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '4':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: COLD\n");
            printf("MEDICINE: HISTACINE\n");
            printf("DOSAGE: 1+0+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld COLD HISTACINE 1+1+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '5':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: COLD\n");
            printf("MEDICINE: HISTACINE\n");
            printf("DOSAGE: 1+0+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld COLD HISTACINE 1+1+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        }
        fclose(fp1);
        j++;
        break;
    case 'G':
        printf("Please Select a doctor from below: \n\n");
        fp1=fopen("Mdoc.dat","r");
        i=1;
        while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
        {
            printf("%d. %s %s %s %s\n",i,s5,s6,s7,s8);
            i++;
        }
        fclose(fp1);
        switch(c=getche())
        {
        case '1':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: GASTRIC\n");
            printf("MEDICINE: MAGNESIUM HYDOXYDE,OMEPRAJOL,ESOMEPRAJOLE\n");
            printf("DOSAGE: 1+0+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld GASTRIC MAGNESIUM HYDOXYDE,OMEPRAJOL,ESOMEPRAJOLE 1+0+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '2':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: GASTRIC\n");
            printf("MEDICINE: MAGNESIUM HYDOXYDE,OMEPRAJOL,ESOMEPRAJOLE\n");
            printf("DOSAGE: 1+0+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld GASTRIC MAGNESIUM HYDOXYDE,OMEPRAJOL,ESOMEPRAJOLE 1+0+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '3':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: GASTRIC\n");
            printf("MEDICINE: MAGNESIUM HYDOXYDE,OMEPRAJOL,ESOMEPRAJOLE\n");
            printf("DOSAGE: 1+0+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld GASTRIC MAGNESIUM HYDOXYDE,OMEPRAJOL,ESOMEPRAJOLE 1+0+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '4':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: GASTRIC\n");
            printf("MEDICINE: MAGNESIUM HYDOXYDE,OMEPRAJOL,ESOMEPRAJOLE\n");
            printf("DOSAGE: 1+0+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld GASTRIC MAGNESIUM HYDOXYDE,OMEPRAJOL,ESOMEPRAJOLE 1+0+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '5':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: GASTRIC\n");
            printf("MEDICINE: MAGNESIUM HYDOXYDE,OMEPRAJOL,ESOMEPRAJOLE\n");
            printf("DOSAGE: 1+0+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld GASTRIC MAGNESIUM HYDOXYDE,OMEPRAJOL,ESOMEPRAJOLE 1+0+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        }
        fclose(fp1);
        j++;
        break;
    case 'P':
        pain();
        break;
    case 'W':
        printf("Please Select a doctor from below: \n\n");
        fp1=fopen("Mdoc.dat","r");
        i=1;
        while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
        {
            printf("%d. %s %s %s %s\n",i,s5,s6,s7,s8);
            i++;
        }
        fclose(fp1);
        switch(c=getche())
        {
        case '1':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: WEEKNESS\n");
            printf("MEDICINE: VIT-B,VIT-C,IRON\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
           fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld WEEKNESS VIT-B,VIT-C,IRON 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '2':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: WEEKNESS\n");
            printf("MEDICINE: VIT-B,VIT-C,IRON\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld WEEKNESS VIT-B,VIT-C,IRON 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '3':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: WEEKNESS\n");
            printf("MEDICINE: VIT-B,VIT-C,IRON\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld WEEKNESS VIT-B,VIT-C,IRON 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '4':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: WEEKNESS\n");
            printf("MEDICINE: VIT-B,VIT-C,IRON\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld WEEKNESS VIT-B,VIT-C,IRON 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '5':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: WEEKNESS\n");
            printf("MEDICINE: VIT-B,VIT-C,IRON\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld WEEKNESS VIT-B,VIT-C,IRON 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        }
        fclose(fp1);
        j++;
        break;
    case 'A':
        printf("Please Select a doctor from below: \n\n");
        fp1=fopen("Mdoc.dat","r");
        i=1;
        while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
        {
            printf("%d. %s %s %s %s\n",i,s5,s6,s7,s8);
            i++;
        }
        fclose(fp1);
        switch(c=getche())
        {
        case '1':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: ANXIYETY\n");
            printf("MEDICINE: DIAGEPAM,CLONAGEPAM\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
           fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld ANXIYETY DIAGEPAM,CLONAGEPAM 1+0+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '2':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: ANXIYETY\n");
            printf("MEDICINE: DIAGEPAM,CLONAGEPAM\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
           fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld ANXIYETY DIAGEPAM,CLONAGEPAM 1+0+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '3':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: ANXIYETY\n");
            printf("MEDICINE: DIAGEPAM,CLONAGEPAM\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
           fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld ANXIYETY DIAGEPAM,CLONAGEPAM 1+0+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '4':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: ANXIYETY\n");
            printf("MEDICINE: DIAGEPAM,CLONAGEPAM\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
           fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld ANXIYETY DIAGEPAM,CLONAGEPAM 1+0+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '5':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: ANXIYETY\n");
            printf("MEDICINE: DIAGEPAM,CLONAGEPAM\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld ANXIYETY DIAGEPAM,CLONAGEPAM 1+0+1,(7 days) %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        }
    case 'R':
        mmenu();
        break;
    default:
        printf("\nPLEASE PRESS CORRECT CHARACTERS ONLY(F,P,C,G,W,A,R)");
        Sleep(500);
        printf(".");
        Sleep(1000);
        printf("  .");
        Sleep(1000);
        printf("  .");
        goto ff;
    }
    printf("\n\n\nSEARCH AGAIN OR RETURN MAIN MENU??");
f:
    gotoxy(1,30);
    era(1,30);
    c=toupper(getche());
    switch(c)
    {
    case 'S':
        geth();
        break;
    case 'R':
        mmenu();
        break;
    default:
        printf("\n\nPLEASE PRESS CORRECT CHARACHTER ONLY(S,R)");
        Sleep(500);
        printf(".  ");
        Sleep(1000);
        printf(".  ");
        Sleep(1000);
        printf(".");
        Sleep(500);
        era(1,20);
        goto f;
    }
}
void pain()
{
    int i,k,l;
    char s5[100],s6[100],s7[100],s8[100],s9[100],s10[10],s11[10],c;
ff:
    system("cls");
    FILE *fp,*fp1;
    //fp=fopen("new sayem medicine.dat","r");
    printf("PLEASE PRESS FIRST LETTER OF YOUR PAIN TYPE OR 'R' FOR RETURNING PREVIOUS MENU\n");
    printf("\n\nHEADACHE BACK-PAIN ARTHRAITIS ");
    gotoxy(1,5);
    c=getche();
    era(1,5);
    switch(toupper(c))
    {
    case 'H':
        printf("Please Select a doctor from below: \n\n");
        fp1=fopen("Mdoc.dat","r");
        i=1;
        while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
        {
            printf("%d. %s %s %s %s\n",i,s5,s6,s7,s8);
            i++;
        }
        fclose(fp1);
        switch(c=getche())
        {
        case '1':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: HEADACHE\n");
            printf("MEDICINE: PARACITAMOL\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld HEADACHE PARACITAMOL 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '2':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: HEADACHE\n");
            printf("MEDICINE: PARACITAMOL\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld HEADACHE PARACITAMOL 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '3':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: HEADACHE\n");
            printf("MEDICINE: PARACITAMOL\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld HEADACHE PARACITAMOL 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '4':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: HEADACHE\n");
            printf("MEDICINE: PARACITAMOL\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld HEADACHE PARACITAMOL 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '5':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: HEADACHE\n");
            printf("MEDICINE: PARACITAMOL\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld HEADACHE PARACITAMOL 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        }
        fclose(fp1);
        j++;
        break;
    case 'B':
        printf("Please Select a doctor from below: \n\n");
        fp1=fopen("Mdoc.dat","r");
        i=1;
        while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
        {
            printf("%d. %s %s %s %s\n",i,s5,s6,s7,s8);
            i++;
        }
        fclose(fp1);
        switch(c=getche())
        {
        case '1':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: BACK-PAIN\n");
            printf("MEDICINE: DICLOFENAC,METRONIDAJOLE\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld BACK-PAIN DICLOFENAC,METRONIDAJOLE 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '2':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: BACK-PAIN\n");
            printf("MEDICINE: DICLOFENAC,METRONIDAJOLE\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld BACK-PAIN DICLOFENAC,METRONIDAJOLE 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '3':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: BACK-PAIN\n");
            printf("MEDICINE: DICLOFENAC,METRONIDAJOLE\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld BACK-PAIN DICLOFENAC,METRONIDAJOLE 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '4':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: BACK-PAIN\n");
            printf("MEDICINE: DICLOFENAC,METRONIDAJOLE\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld BACK-PAIN DICLOFENAC,METRONIDAJOLE 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '5':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: BACK-PAIN\n");
            printf("MEDICINE: DICLOFENAC,METRONIDAJOLE\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld BACK-PAIN DICLOFENAC,METRONIDAJOLE 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        }
        fclose(fp1);
        j++;
        break;
    case 'A':
        printf("Please Select a doctor from below: \n\n");
        fp1=fopen("Mdoc.dat","r");
        i=1;
        while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
        {
            printf("%d. %s %s %s %s\n",i,s5,s6,s7,s8);
            i++;
        }
        fclose(fp1);
        switch(c=getche())
        {
        case '1':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: ARTHRAITIS\n");
            printf("MEDICINE: TRAMADOL,OXYCODONE\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
           fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld ARTHRAITIS TRAMADOL,OXYCODONE 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '2':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: ARTHRAITIS\n");
            printf("MEDICINE: TRAMADOL,OXYCODONE\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld ARTHRAITIS TRAMADOL,OXYCODONE 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '3':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: ARTHRAITIS\n");
            printf("MEDICINE: TRAMADOL,OXYCODONE\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
           fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld ARTHRAITIS TRAMADOL,OXYCODONE 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '4':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: ARTHRAITIS\n");
            printf("MEDICINE: TRAMADOL,OXYCODONE\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
            fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld ARTHRAITIS TRAMADOL,OXYCODONE 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        case '5':
            printf("\n\nPATIENT ID: %lld\n",j);
            printf("Rx:\n\n");
            printf("DISEASE: ARTHRAITIS\n");
            printf("MEDICINE: TRAMADOL,OXYCODONE\n");
            printf("DOSAGE: 0+1+1 (7 days)\n");
            printf("DATE: %lld-%lld-%lld\n",D()/10000,(D()/100-((D()/10000)*100)),D()%100);
            i=1;
           fp1=fopen("Mdoc.dat","r");
            while(fscanf(fp1,"%s %s %s %s %s %s %s",s5,s6,s7,s8,s9,s10,s11)!=EOF)
            {
                if(i==c-48)
                    break;
                i++;
            }
            fclose(fp1);
            printf("DOCTOR TO BE CONSULTED: %s %s %s\n",s5,s6,s7);
            printf("VISITING TIME: %s\n",s10);
            printf("VISITING PLACE: %s\n",s9);
            printf("DOCTOR VISIT: %s\n",s11);
            printf("(PLEASE PRESERVE YOUR PATIENT ID FOR FUTURE PURPOSE)\n");
            itoa(j,s,10);
            strcat(s10,".dat");
            fp=fopen(s10,"w");
            fprintf(fp,"%lld ARTHRAITIS TRAMADOL,OXYCODONE 1+1+1 %lld %lld %lld %s %s\n",j,D()/10000,(D()/100-((D()/10000)*100)),D()%100,s5,s6);
            fclose(fp);
            break;
        }
        fclose(fp1);
        j++;
        break;
    case 'R':
        geth();
        break;
    default:
        printf("\nPLEASE PRESS CORRECT CHARACTERS ONLY(H,B,A,R)");
        Sleep(500);
        printf(".");
        Sleep(1000);
        printf("  .");
        Sleep(1000);
        printf("  .");
        goto ff;
    }
    printf("\n\n\nSEARCH AGAIN OR RETURN MAIN MENU??");
f:
    gotoxy(1,30);
    era(1,30);
    c=toupper(getche());
    switch(c)
    {
    case 'S':
        geth();
        break;
    case 'R':
        geth();
        break;
    default:
        printf("\n\nPLEASE PRESS CORRECT CHARACHTER ONLY(S,R)");
        Sleep(500);
        printf(".  ");
        Sleep(1000);
        printf(".  ");
        Sleep(1000);
        printf(".");
        Sleep(500);
        era(1,30);
        goto f;
    }

}

