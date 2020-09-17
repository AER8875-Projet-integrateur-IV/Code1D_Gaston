//
//  main.cpp
//  EqOndes
//
//  Created by Gaston Banna on 2020-09-16.
//  Copyright © 2020 Gaston Banna. All rights reserved.
//

#include<iostream>
#include<stdio.h>
#include<math.h>

#define L 100
#define c 300
#define T 100

int main()
{
    float u[T+3][L+3],CFL,dx,dt;
    int n,j;
    CFL = 1;
    dx = 1;
    dt = CFL/c*dx;
    for(j=42;j<=62;j++)
    u[0][j]=100;
    for(j=1;j<=T-1;j++)
    for(n=1;n<=L-1;n++)
    u[n+1][j]=u[n][j]-c*dt/dx*(u[n][j]-u[n][j-1]);
    printf(" Les valeurs de u[n][j] (Backward) sont: \n");
    for(j=0;j<=L;j++)
    {
        for(n=0;n<=L;n++)
        printf("%6.1f",u[n][j]);
        printf("\n");
    }

    for(j=42;j<=62;j++)
    u[0][j]=100;
    for(j=1;j<=T-1;j++)
    for(n=1;n<=L-1;n++)
    u[n+1][j]=u[n][j]-c*dt/dx*(u[n][j+1]-u[n][j-1])/2;
    printf(" Les valeurs de u[n][j] (Center) sont: \n");
    for(j=0;j<=L;j++)
    {
        for(n=0;n<=L;n++)
        printf("%6.1f",u[n][j]);
        printf("\n");
    }
    
    for(j=42;j<=62;j++)
        u[0][j]=100;
        for(j=1;j<=T-1;j++)
        for(n=1;n<=L-1;n++)
        u[n+1][j]=u[n][j]-c*dt/dx*(u[n][j+1]-u[n][j]);
        printf(" Les valeurs de u[n][j] (Forward) sont: \n");
        for(j=0;j<=L;j++)
        {
            for(n=0;n<=L;n++)
            printf("%6.1f",u[n][j]);
            printf("\n");
        }
}
