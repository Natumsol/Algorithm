typedef int ElementType ;
#define NotFound -1;
/************************************************************************/
/* ¶þ·Ö²éÕÒ                                                                     */
/************************************************************************/
int binarySearch(ElementType A[], ElementType X, int N){
	int low, high, middle;
	low = 0; high = N - 1;
	while(low < high) {
		middle = (low + high) / 2;
		if(X > A[middle]){
			low = middle + 1;
		} else if(X < A[middle]) {
			high = middle - 1;
		} else{
			return middle;
		}
	}
	return NotFound;
}