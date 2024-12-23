#pragma once

#include "CoreMinimal.h"
#include "ItemStruct.h"
#include "Containers/Array.h"

template <typename T>
class FPriorityQueue
{
public:
    // Adds an item to the priority queue
    void Push(const T& Item)
    {
        // Add the new item to the end of the heap
        Items.Add(Item);
        // Bubble up the item to maintain the heap property
        BubbleUp(Items.Num() - 1);
    }

    // Removes and returns the item with the highest priority
    T Pop()
    {
        if (Items.Num() == 0)
        {
            return T(); // Return default value if empty
        }

        // Swap the first item (highest priority) with the last
        T ItemToReturn = Items[0];
        Items[0] = Items.Last();
        Items.RemoveAt(Items.Num() - 1);

        // Bubble down the root to restore the heap property
        BubbleDown(0);

        return ItemToReturn;
    }

    // Returns the item with the highest priority without removing it
    const T& Top() const
    {
        if (Items.Num() > 0)
        {
            return Items[0];
        }
        return T(); // Return default value if empty
    }

    // Checks if the priority queue is empty
    bool IsEmpty() const
    {
        return Items.Num() == 0;
    }

private:
    // Array to store the heap
    TArray<T> Items;

    // Bubble up the item at index i to maintain the heap property
    void BubbleUp(int32 Index)
    {
        int32 ParentIndex = (Index - 1) / 2;
        if (Index > 0 && Items[Index] < Items[ParentIndex]) // Swap condition for max-heap
        {
            // Swap and recursively bubble up
            Swap(Items[Index], Items[ParentIndex]);
            BubbleUp(ParentIndex);
        }
    }

    // Bubble down the item at index i to maintain the heap property
    void BubbleDown(int32 Index)
    {
        int32 LeftChildIndex = 2 * Index + 1;
        int32 RightChildIndex = 2 * Index + 2;

        int32 HighestPriorityIndex = Index;

        // Check if the left child exists and has higher priority
        if (LeftChildIndex < Items.Num() && Items[LeftChildIndex] < Items[HighestPriorityIndex])
        {
            HighestPriorityIndex = LeftChildIndex;
        }

        // Check if the right child exists and has higher priority
        if (RightChildIndex < Items.Num() && Items[RightChildIndex] < Items[HighestPriorityIndex])
        {
            HighestPriorityIndex = RightChildIndex;
        }

        // If the highest priority item is not the current one, swap
        if (HighestPriorityIndex != Index)
        {
            // Swap and recursively bubble down
            Swap(Items[Index], Items[HighestPriorityIndex]);
            BubbleDown(HighestPriorityIndex);
        }
    }
};