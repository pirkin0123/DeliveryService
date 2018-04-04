#pragma once

#define DAY 31         // t �W����� 
#define DISTRICT 4     // j �ϰ� 
#define FLEET 8        // i �ۦ����� 
#define TASK 2         // k ����:���f&�~�e 
#define CAR_TYPE 3     // n �M��1.2.3 
#define STATION 2      // m ��L��B���߼�  

#define SCENARIO 50    // s �H�����p 
#define POLULATION 50
#define TRUCK 2        // ����17ton truck & container truck

#define MAXWORKTIME 12 // �̤j�i�u�@�ɶ� 
#define WORKTIME 0.5   // ���Ҩ��e�f�ɶ�  hr

#define COST_TEMPORARY_OUTSOURCING17 2   // �~�]17���f���{�ɰt�e�������v
#define COST_TEMPORARY_17 2.5            // �ۦ������{�ɰt�e�������v
#define COST_OUTSOURCING_CONTAINER 1.45  // �~�]�f�d����ϰ���Ȥ��������v(�ۦ���*1.45) a1jk

#include <array>

template <class T, size_t I, size_t... J>
struct MultiDimArray
{
	using Nested = typename MultiDimArray<T, J...>::type;
	// typedef typename MultiDimArray<T, J...>::type Nested;
	using type = std::array<Nested, I>;
	// typedef std::array<Nested, I> type;
};

template <class T, size_t I>
struct MultiDimArray<T, I>
{
	using type = std::array<T, I>;
	// typedef std::array<T, I> type;
};