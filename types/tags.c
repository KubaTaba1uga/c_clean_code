/* Tag is a type name  */

int main(void){
	/* `s` is a tag */
	struct s {
	  int counter;
	};

	/* tag canno't be used in  */
	/* 	place of a type */

	/* wrong declaration*/
	//  s a;

	/* good declaration */
	struct s a;

	/* because tags are defined in */
	/* 	another namespace than */
	/* 	variables names, their  */
	/* 	collision is impossible */
	struct s s;

	/* adding type's alias lead */
	/* 	to shorten notation */
	typedef struct s x;

	/* good declaration */
	x b;

        return 0;
}
