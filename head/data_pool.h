//
// Created by HN on 2022/5/19.
//
#include <stdio.h>
#include <malloc.h>

#ifndef DATA_POOL_DATA_POOL_H
#define DATA_POOL_DATA_POOL_H

typedef struct data_pool{
    int length;
    int last;
    int* poolPtr;

}data_pool;

/*
 * @brief 初始化一个data_pool
 * 
 * @parameter l data_pool的深度
 *
 * @return NULL 初始化失败，没有满足深度的连续内存空间
 *         data_pool* 初始化成功，返回一个data_pool指针
 *
 * */
data_pool* data_pool_init(int l);



#endif //DATA_POOL_DATA_POOL_H
