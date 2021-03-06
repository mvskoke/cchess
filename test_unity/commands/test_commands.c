#include "../../src/commands.h"
#include "../../unity/unity.h"

void setUp(void) {}
void tearDown(void) {}

/* Sorry Unity devs, but I don't use camelCase. */

/* These should always return MOVE */
void test_legal_moves(void)
{
	TEST_ASSERT_EQUAL(MOVE, validate_command("e2e4"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("e7e5"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("a1a7"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("e8g2"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("e1g1"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("c3b6"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("e5f6"));
}

/* These should always return ILLEGAL */
void test_illegal_moves(void)
{
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("a1a1"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("a9a9"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("e8e9"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("a1h9"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("a9a1"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("ksdjf"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("z8z8"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("z6j8"));

	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("a1a1q"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("a9a9q"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("e8e9q"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("a1h9b"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("a9a1b"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("z8z8n"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("z6j8r"));
}

/* These should always return MOVE */
void test_pawn_promotion(void)
{
	TEST_ASSERT_EQUAL(MOVE, validate_command("a7a8q"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("a7a8r"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("a7a8b"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("a7a8n"));

	TEST_ASSERT_EQUAL(MOVE, validate_command("a7b8q"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("a7b8r"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("a7b8b"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("a7b8n"));

	TEST_ASSERT_EQUAL(MOVE, validate_command("e7d8q"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("e7d8r"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("e7d8b"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("e7d8n"));

	TEST_ASSERT_EQUAL(MOVE, validate_command("e7e8q"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("e7e8r"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("e7e8b"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("e7e8n"));

	TEST_ASSERT_EQUAL(MOVE, validate_command("e7f8q"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("e7f8r"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("e7f8b"));
	TEST_ASSERT_EQUAL(MOVE, validate_command("e7f8n"));
}

/* These should always return one of the command enums */
void test_legal_commands(void)
{
	TEST_ASSERT_EQUAL(RESIGN, validate_command("r"));
	TEST_ASSERT_EQUAL(DRAW, validate_command("d"));
	TEST_ASSERT_EQUAL(FLIP, validate_command("f"));
	TEST_ASSERT_EQUAL(HELP, validate_command("h"));
	TEST_ASSERT_EQUAL(QUIT, validate_command("q"));

	TEST_ASSERT_EQUAL(RESIGN, validate_command("R"));
	TEST_ASSERT_EQUAL(DRAW, validate_command("D"));
	TEST_ASSERT_EQUAL(FLIP, validate_command("F"));
	TEST_ASSERT_EQUAL(HELP, validate_command("H"));
	TEST_ASSERT_EQUAL(QUIT, validate_command("Q"));
}

/* These should always return ILLEGAL */
void test_illegal_commands(void)
{
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("win"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("free checkmate"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("cheats"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("gcc -Wall -Werror -Wextra -g main.c -o main"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("ksdjbf"));

	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("uzi hitman is a really good singer and you should check out his music"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("^^^ seriously tho you should: https://www.youtube.com/watch?v=GowEIZKbVuc"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("123456"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command(""));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("enyniwy58qcfn57q65dq7835dq783y5oqwyqdoay35dq7o45yqo7y54o7qy4o87qyd578qoy4f78qoay4d87oqy45d87oa7y54a87y5a7uy7ao85ynn7aow4y6289nc573298c789q7nc8w9urcoiseu5w35y9n8wncy297ycqniuuaowruq28m5985yn9820000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("I LOOOOOVE CHESS!!! :))))"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("i hate chess :( wahhhh"));
	//TEST_ASSERT_EQUAL(ILLEGAL, validate_command("rm / -rf"));
	// I'm too scared to try this test. I know it shouldn't do anything, but I can't do it.
	// Will you, the reader reviewing this code, have the faith to try?

	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("rr"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("dd"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("ff"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("hh"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("qq"));

	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("RR"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("DD"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("FF"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("HH"));
	TEST_ASSERT_EQUAL(ILLEGAL, validate_command("QQ"));
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_legal_moves);
	RUN_TEST(test_illegal_moves);
	RUN_TEST(test_pawn_promotion);
	RUN_TEST(test_legal_commands);
	RUN_TEST(test_illegal_commands);
	return UNITY_END();
}
