# Κάνοντας compile το <foo>_test.c με μια υλοποίηση <foo>.c του
# συγκεκριμένου τύπου, παράγουμε ένα tets για την υλοποίηση αυτή.

# Υλοποιήσεις μέσω ADTStack: ADTQueue
# Για να λειτουργήσουν χρειάζονται και μια υλοποίηση του ADTStack. Χρησιμοποιούμε την UsingADTList/ADTStack.o,
# η οποία με τη σειρά της χρειάζεται μια υλοποίηση του ADTList (χρησιμοποιούμε την UsingLinkedList/ADTList.o).
#
#edw
ADTQUEUE_STACK_ALT = $(MODULES)/UsingADTStack/ADTQueue_alt.o  
ADTQUEUE_STACK = $(MODULES)/UsingADTStack/ADTQueue.o

ADTSTACK_LIST = $(MODULES)/UsingADTList/ADTStack.o
ADTLIST = $(MODULES)/UsingLinkedList/ADTList.o
ADTVECTOR = $(MODULES)/UsingDynamicArray/ADTVector.o

UsingADTStack_ADTQueue_test_OBJS = ADTQueue_test.o $(ADTQUEUE_STACK) $(ADTSTACK_LIST) $(ADTLIST) $(ADTVECTOR)

UsingADTStack_alt_ADTQueue_test_OBJS = ADTQueue_test.o $(ADTQUEUE_STACK_ALT) $(ADTSTACK_LIST) $(ADTLIST) $(ADTVECTOR)

# Υλοποιήσεις μέσω ADTList: ADTQueue
# Πέρα από το .o της κάθε υλοποίησης (πχ ADTStack.o), χρειάζεται και μια υλοποίηση του ίδιου του ADTList!
#
#UsingADTList_ADTQueue_test_OBJS = ADTQueue_test.o $(MODULES)/UsingADTList/ADTQueue.o $(MODULES)/UsingLinkedList/ADTList.o

# Υλοποιήσεις μέσω BinarySearchTree: ADTSet
#
#UsingBinarySearchTree_ADTSet_test_OBJS = ADTSet_test.o $(MODULES)/UsingBinarySearchTree/ADTSet.o

# Ο βασικός κορμός του Makefile
include ../common.mk