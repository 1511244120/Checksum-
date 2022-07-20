#include <iostream>
#include <climits>

#ifndef MARMOSET_TESTING
int main();
#endif

unsigned int add_checksum(unsigned int n);
unsigned int add_checksum(unsigned int n){
    unsigned int number{n};
	int result{0};
	int counter{0};
	if (n>99999999){
		return UINT_MAX;
	}
	while (n>0){
		int remainder{0};
		if (counter%2 == 0){
			remainder = (n%10)*2;
			if (remainder>9){
				if (remainder==10){
					remainder=1;
				}else if (remainder==11){
					remainder=2;
				}else if (remainder==12){
					remainder=3;
				}else if (remainder==13){
					remainder=4;
				}else if (remainder==14){
					remainder=5;
				}else if (remainder==15){
					remainder=6;
				}else if (remainder==16){
					remainder=7;
				}else if (remainder==17){
					remainder=8;
				}else if (remainder==18){
					remainder=9;
				}
			}
		}else if(counter%2 == 1){
			remainder = n%10;
		}
		counter = counter +1;
		result = result+remainder;
		n /= 10;
	}
	result =(result*9)%10;
    result = number*10 + result;
    
	
	return result;
}
void add_checksum(unsigned int array[], std::size_t capacity);
void add_checksum(unsigned int array[], std::size_t capacity){
    for (int i{0}; i<capacity; ++i){
        array[i]=add_checksum(array[i]);
    }
    return;
}
bool verify_checksum(unsigned int n);
bool verify_checksum(unsigned int n){
	if ((n>999999999)||((n%10) != ((add_checksum(n/10))%10))){
		return false;
	}else{
		return true;
	}
}
unsigned int remove_checksum(unsigned int n);
unsigned int remove_checksum(unsigned int n){
	if (verify_checksum(n)){
		return n/10;
	}else{
		return UINT_MAX;
	}
}
void remove_checksum(unsigned int array[], std::size_t capacity);
void remove_checksum(unsigned int array[], std::size_t capacity){
	for (int i{0}; i<capacity; ++i){
		array[i]=remove_checksum(array[i]);
	}
}
#ifndef MARMOSET_TESTING
int main() {
	unsigned int value_to_protect{21352411};
	unsigned int protected_value = add_checksum(value_to_protect);
	std::cout << "The value " << value_to_protect
		<< " with the checksum added is " << protected_value
		<< "." << std::endl;
	
	if (verify_checksum(protected_value))
	{
		std::cout << "The checksum is valid." << std::endl;
	}
	else   {
		std::cout << "The checksum is invalid." << std::endl;
	} 
	const std::size_t QTY_VALUES {3};
	unsigned int value_series[QTY_VALUES] {20201122, 20209913, 20224012};
	
	add_checksum(value_series, QTY_VALUES);
	
	std::cout << "Series with checksums added: ";
	for (std::size_t series_index {0};
		series_index < QTY_VALUES; series_index++)
	{
		std::cout << value_series[series_index] << " ";
	}

    std::cout << std::endl;
    return 0;
}
#endif