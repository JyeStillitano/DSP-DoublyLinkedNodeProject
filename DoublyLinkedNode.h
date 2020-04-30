
// COS30008, Tutorial 7, 2020

#pragma once

template<class DataType>
class DoublyLinkedNode
{
public:
    typedef DoublyLinkedNode<DataType> Node;	// nominal equivalence
    
private:
    DataType fValue;    // stored datum
    Node* fNext;        // forward pointer to next element
    Node* fPrevious;    // backward pointer to previous element
    
    // private default constructor for sentinel (not used elsewhere)
    DoublyLinkedNode()
    {
        fValue = DataType();        // initialize variable with DataType default
        fNext = &NIL;               // set forward pointer to Nil
        fPrevious = &NIL;           // set backwards pointer to Nil
    }
    
public:
    static Node NIL;                            // sentinel declaration
  
    DoublyLinkedNode(const DataType& aValue)
    {
        fValue = aValue;
        fNext = &NIL;
        fPrevious = &NIL;
    }

    void push_front(Node& aNode)
    {
        if (fPrevious != &NIL)
        {
            aNode.fPrevious = fPrevious;
            fPrevious->fNext = &aNode;
        }
        fPrevious = &aNode;
        aNode.fNext = this;
    }
    void push_back(Node& aNode)
    {
        if (fNext != &NIL)
        {
            fNext->fPrevious = &aNode;
            aNode.fNext = fNext;
        }
        fNext = &aNode;
        aNode.fPrevious = this;
    }
    void remove()
    {
        if (fPrevious != &NIL)
        {
            fPrevious->fNext = fNext;
        }
        if (fNext != &NIL)
        {
            fNext->fPrevious = fPrevious;
        }
        fPrevious = &NIL;
        fNext = &NIL;
    }
    const DataType& getValue() const
    {
        return fValue;
    }
    const Node& getNext() const
    {
        return *fNext;
    }
    const Node& getPrevious() const
    {
        return *fPrevious;
    }
};

// sentinel implementation
template<class DataType>
DoublyLinkedNode<DataType> DoublyLinkedNode<DataType>::NIL;