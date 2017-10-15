#include<stdio.h>
#include<stdlib.h>

typedef struct heap{
	int* array;
	int count;
	int capacity;
	
}heap;
heap* createHeap(int capacity){
	heap* h=(heap*)malloc(sizeof(heap));
	h->count=0;
	h->capacity=capacity;
	h->array=(int*)malloc(sizeof(int)*h->capacity);
	return h;
}
void proclateDown(heap* h,int i);
int insert(heap* h,int data);
int leftChild(heap* h,int i);
int rightChild(heap* h,int i);
int parent(heap* h,int i); 
void proclateUpward(heap* h,int i);
int deleMin(heap* h);
int isEmpty(heap *h);
void destroyHeap(heap* h);

int insert(heap* h,int data){
	int i;h->count++;
	i=h->count-1;
	while(i>0&&data< h->array[(i-1)/2]){
		h->array[i]=h->array[(i-1)/2];
		i=(i-1)/2;
	}
	h->array[i]=data;
    proclateUpward( h,i);
}
int leftChild(heap* h,int i){
	int left=2*i+1;
	if(left>= h->count) return -1;
	return left;
}
int rightChild(heap* h,int i){
	int right= 2*i+2;
	if(right >=h->count) return -1;
	return right;
}
int parent(heap* h,int i){
	if(i<=0|| i>= h->count) return -1;
	return (i-1)/2;
	
}
 void proclateUpward(heap* h,int i){
	 int p=parent(h,i); int temp;
	 if(p== -1) return ;
	 if(p!= -1 && (h->array[p]>h->array[i])){
		 temp=h->array[i];
		 h->array[i]=h->array[p];
		 h->array[p]=temp;
		 proclateUpward(h,p);
	 }
 }
 void proclateDown(heap* h,int i){
	int l,r,min;
	int temp;
	l=leftChild(h,i);
	r=rightChild(h,i);
	if(l!= -1&& h->array[l]< h->array[i])
		min = l;
	else min= i;
	if(r!= -1 && h->array[r] < h->array[min])
		min = r;
	 if(min ==i) return;
	 if(min!= i){
		 temp=h->array[i];
		 h->array[i]=h->array[min];
		 h->array[min]=temp;
		 
	 }
	 proclateDown(h,min);// check here 
	 
}
int deleMin(heap* h){
	int vertex;
	if(h->count== 0) return -1;
	
	//int dara=h->array[0].data;
	vertex=h->array[0];
	h->array[0]=h->array[h->count-1];
	h->count--;
	proclateDown(h,0); 
	return vertex;
	
}
int isEmpty(heap *h){
	if(h->count==0) return 1;
	else return 0;
}
 void destroyHeap(heap* h){
	 if(h==NULL)
		 return;
	 free(h->array);
	 free(h);
	 h=NULL;
 }
int main(){ int i;
	heap* h=createHeap(100);
	insert(h,13);
	insert(h,6);
	insert(h,9);
	insert(h,2);insert(h,50);
	insert(h,12);
	insert(h,10);
	insert(h,5);
	insert(h,3);
	insert(h,7);
	insert(h,0);
	insert(h,0);
	insert(h,1);
	for(i=0;i<12;i++){printf("  %d",deleMin(h));}
}