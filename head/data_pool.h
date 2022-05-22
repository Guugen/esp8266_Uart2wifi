//
// Created by HN on 2022/5/19.
//
#include <stdio.h>
#include <malloc.h>

#ifndef DATA_POOL_DATA_POOL_H
#define DATA_POOL_DATA_POOL_H

#define DATATYPE uint8_t  

typedef struct Data_pool{
    uint8_t length;
    uint8_t last;
    DATATYPE* poolPtr;

}Data_pool;

/*
 * @brief 初始化一个data_pool
 * 
 * @parameter l data_pool的深度
 * @parameter Ptr a pointer to data_pool
 *
 * @return NULL 初始化失败，没有满足深度的连续内存空间
 *         data_pool* 初始化成功，返回一个data_pool指针
 *
 * */
_Bool Data_pool_init(int l, Data_pool *Ptr);



#endif //DATA_POOL_DATA_POOL_H
