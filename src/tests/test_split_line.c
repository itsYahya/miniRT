#include "tests.h"

static void	test_count_words()
{
	assert(count_words("") == 0);
	assert(count_words(0) == 0);
	assert(count_words("        ") == 0);
	assert(count_words("j") == 1);
	assert(count_words("here") == 1);
	assert(count_words("     h") == 1);
	assert(count_words("h		") == 1);
	assert(count_words("h  ") == 1);
	assert(count_words("     h ") == 1);
	assert(count_words("here we") == 2);
	assert(count_words("here we   ") == 2);
	assert(count_words("here we ") == 2);
	assert(count_words("here we go") == 3);
}

char	**arr;
# define EXPECT_SIZE(SIZE, STR) \
	arr = split_by_space(STR); \
	assert(ft_arr_size(arr) == SIZE); \
	ft_arr_free(arr)

static void	test_split_by_space_()
{
	char	**arr;

	EXPECT_SIZE(2, "test test");
	EXPECT_SIZE(0, "");
	EXPECT_SIZE(1, "f         ");
	EXPECT_SIZE(1, "     f");
	EXPECT_SIZE(7, "sp\t\t\t\t 0.0,0,10 \v\t\r5 0,1,255       \t0.6    1       200");
}

void	test_split_by_space()
{
	printf("test count words: ");
	test_count_words();
	printf("OK\n");
	printf("test split line: ");
	test_split_by_space_();
	printf("OK\n");
}
