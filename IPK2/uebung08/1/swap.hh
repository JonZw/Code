#ifndef SWAP_HH
#define SWAP_HH

template<typename a>
void swap(a& a1,a& b1)
{
	
	auto t=a1;
	a1=b1;
	b1=t;
} 

#endif // SWAP_HH
