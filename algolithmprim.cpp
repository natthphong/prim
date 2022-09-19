#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <dos.h>
#include <time.h>
#include <iostream>
#include <string.h>

void open_gr()
{
    //int gdriver=DETECT,gmode;
    // initgraph(&gdriver,&gmode,"C:\TDM-GCC-32\mingw32");
    initwindow(1500,700);
}

int prim(int n,int m,int A[][1000],int x,int dot[][2])
{
    open_gr();
    x = x-1;  
    int pr[n+1][2]; 
    int B[n+1][2]; 

    for(int i = 0; i<n; i++)
    {
        B[i][0] = 0; 
        B[i][1] = -1; 
    }

    int O[n+2] ; 
    for(int i = 0; i<n; i++)
    {
        O[i] = 0; 
    }

    int sum = 0;

    int left[n+1],top[n+1],right[n+1],bottom[n+1];

    for(int r=0; r<n; r++)
    {
        top[r]=20+(30*(r));
        bottom[r]=50+(30*(r));
        for(int c=0; c<=n; c++)
        {
            left[c]=20+(80*(c));
            right[c]=100+(80*(c));

        }
    }
    int start[100];
    int vertex[100][100];
    int weight[100][100];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            vertex[i][j]=-1;
            weight[i][j]=-1;
        }
    }

    for(int i = 0; i<n-1; i++)
    {
        pr[i][0] = x; 
        int min = 999999;
        O[x] = 1; 
        
        for(int j=0; j<n; j++)
        {
            if(A[x][j]!=0&&O[j]==0)
            {
               
                if(B[j][0]==0)
                {
                    B[j][0] = A[x][j];
                    B[j][1] = x+1;
                }
                else if(A[x][j]<B[j][0]&&B[j][0]!=0)
                {
                    B[j][0] = A[x][j];
                    B[j][1] = x+1;
                }
            }
        }
       
        start[i]=x+1;

        for(int j=0; j<n; j++)
        {
            if(B[j][0]<min&&O[j]==0&&B[j][0]!=0)
            {
                min = B[j][0];
                pr[i][1] = B[j][1]-1;
                x = j;
            }
            if(O[j]==1)
            {

               // printf("---|");
                vertex[i][j]=-2;
                weight[i][j]=-2;

            }
            else if(B[j][1]==-1)
            {
              //  printf("INF |");
                vertex[i][j]=0;
                weight[i][j]=0;

            }
            else
            {
                //printf("%d,",B[j][0]);
               // printf("Vb%d|",B[j][1]);
                weight[i][j]=B[j][0];
                vertex[i][j]=B[j][1];

            }

        }

       
        sum+=min;
     
        if(i+1==n-1)
        {
            for(int j=0; j<n; j++)
            {
                if(O[j]==0)
                {
                    pr[i+1][0] = j;
                    pr[i+1][1] = B[j][1]-1;
                }
            }
        }
    }

    for(int i=0; i==0; i++)
    {
        setcolor(11);

        for(int j=0; j<=n; j++)
        {

            if(j==0)
            {
                outtextxy(left[j]+30, top[i]+10,"N" );
                rectangle(left[j],top[i],right[j],bottom[i]);
            }
            else if(j>=1)
            {
                char V[100];
                sprintf(V,"%d",j); 
                strcat(V,"V");
                outtextxy(left[j]+30, top[i]+10,V);
                rectangle(left[j],top[i],right[j],bottom[i]);
            }

        }

    }
    int i=1;

    while(i<n)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
          setcolor(9);
            for(int j=0; j<=n; j++)
            {
                if(start[i-1]<=n) 
                {
                    if(j==0)
                    {
                        char ver[100];
                        sprintf(ver,"%d",start[i-1]); 
                        strcat(ver,"V");
                        outtextxy(left[j]+30, top[i]+10, ver);
                        rectangle(left[j],top[i],right[j],bottom[i]);
                    }
                    else if(j>=1)
                    {
                        if(vertex[i-1][j-1]==-2)
                        {
                            outtextxy(left[j]+30, top[i]+10, "---");
                            rectangle(left[j],top[i],right[j],bottom[i]);
                        }
                        else if(vertex[i-1][j-1]==0)
                        {
                            outtextxy(left[j]+30, top[i]+10, "INF");
                            rectangle(left[j],top[i],right[j],bottom[i]);
                        }
                        else
                        {

                            char rsweight[100];
                            sprintf(rsweight,"%d",weight[i-1][j-1]); 
                            strcat(rsweight," ,V");
                            outtextxy(left[j]+20, top[i]+10, rsweight);
                            char rsvertex[100];
                            sprintf(rsvertex,"%d",vertex[i-1][j-1]);
                            strcat(rsvertex,"");
                            outtextxy(left[j]+45, top[i]+10, rsvertex);
                            rectangle(left[j],top[i],right[j],bottom[i]);
                        }
                    }
                }
            }

            clearmouseclick(WM_LBUTTONDOWN);
            i++;
        }

        int color=3;
        if(i==n)
        {
           setcolor(9);
            outtextxy(645, 655, "sum");
            char sumprim[100];
            sprintf(sumprim,"%d",sum); 
            strcat(sumprim," ");
            outtextxy(685, 655, sumprim);
            rectangle(640,650,710,680);
        }

    }

    for(int z=n; z>0; z--)
    {

        pr[z][1]=pr[z-1][1];
    }

    open_gr();
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(20, 20, "Graph algolithm Prim");
    int color =1;

    setcolor(color);
/// �絨ش�ͧ��ҿ
    for(int z=0; z<n; z++)
    {

        setcolor(14);
        char V[20];
        sprintf(V,"%d",z+1);
        strcat(V,"V");
        circle(dot[z][0], dot[z][1],5);
        settextstyle(0,0,2);
        outtextxy(dot[z][0],dot[z][1],V);
    }
///����鹢ͧ��ҿ
    setcolor(15);
    for(int z=1; z<n; z++)
    {


        int x = pr[z][0];
        int tox = pr[z][1];
        char E[20];
        sprintf(E,"%d",B[x][0]);
        strcat(E,"");
        line(dot[x][0],dot[x][1],dot[tox][0],dot[tox][1]);
        outtextxy((dot[x][0]+dot[tox][0])/2, (dot[x][1]+dot[tox][1])/2,E);

    }
//delay(20000);

    return sum;

}

int  main()
{
    int n,sumdot=0;
    printf(" N  : ");
    scanf("%d",&n);
    int dot[n][2];
    printf(" Metrix  : \n");
    int Arr[n][1000];
    for(int i =0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            scanf("%d",&Arr[i][j]);
        }

    }
    printf(" start : ");
    int k;
    scanf("%d",&k);

    int x, y,numvertex=0;        // Coordinates of the mouse click

    // Put the machine into graphics mode and get the maximum coordinates:
    open_gr();
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(20, 20, "Left click to create vertex");

    int color =1;


    while  (numvertex<n)
    {

        if(ismouseclick(WM_LBUTTONDOWN))
        {
            char V[20];
            sprintf(V,"%d",sumdot+1);
            strcat(V,"V");
            if(color == 15)
            {
                color = 1;
            }
            setcolor(color);
            int x =  mousex();
            int y =  mousey();
            numvertex++;
            dot[sumdot][0] = x;
            dot[sumdot][1] = y;
            circle(dot[sumdot][0], dot[sumdot][1],5);
            settextstyle(0,0,2);
            outtextxy(dot[sumdot][0],dot[sumdot][1],V);
            clearmouseclick(WM_LBUTTONDOWN);
            sumdot++;
            color++;
        }

    }

    color =1;
    char E[20];

    for(int i=0; i<n; i++)
    {
        setcolor(color);
        for(int j=0; j<n; j++)
        {
            sprintf(E,"%d",Arr[i][j]);
            strcat(E,"");

            if(color == 15)
            {
                color = 1;
            }
            if(Arr[i][j]!=0)
            {

                outtextxy((dot[i][0]+dot[j][0])/2, (dot[i][1]+dot[j][1])/2,E);
                line(dot[i][0],dot[i][1],dot[j][0],dot[j][1]);
                //settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

            }
        }
        color++;

    }
    int all = prim(n,n,Arr,k,dot);
  //  printf("minimum : %d", all);
    getch();
    closegraph();
    return 0;

}
