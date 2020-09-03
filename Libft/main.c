#include "libft.h"

int main()
{
	printf("In : [%f] || Out : [%s]\n", 198756.1234567890, ft_dtoa(198756.1234567890));
    printf("In : [%f] || Out : [%s]\n", 3.0, ft_dtoa(3.0));
    printf("In : [%f] || Out : [%s]\n", 12.45, ft_dtoa(12.45));
    printf("In : [%f] || Out : [%s]\n", 9852.9852, ft_dtoa(9852.9852));
    printf("In : [%f] || Out : [%s]\n", 10000.999999, ft_dtoa(10000.999999));
    printf("In : [%f] || Out : [%s]\n", 1.5, ft_dtoa(1.5));
    return (0);
}