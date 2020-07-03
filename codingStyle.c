/*
 * Sample file using the Linux kernel coding convention.
 *
 *  https://www.kernel.org/doc/Documentation/CodingStyle
 *
 * General rules:
 *  - Indents are tabs and must be 8 spaces wide.
 *  - Each line must be at most 80 characters long.
 *  - Use C-style comments.
 *  - File names should be lower-case.c
 *
 * Copied from:
 * https://gist.github.com/davidzchen/9187984.js
 */

#include <stdlib.h>
#include <stdbool.h>

/* For macros, use ALL_CAPS separated by underscore: */
#define FLAG_FOO 0x0

/*
 * If a macro's replacement is not just a literal, enclose it in parentheses:
 */
#define FLAG_BAZ (0x1 << 3)

/*
 * It appears that the Linux kernel codebase tends to use #defines for
 * constants. Global constants are treated similar to global variables.
 */
const int state_foo = 0;

/* Enum values can either look like macros: */
enum mode {
	MODE_FOO,
	MODE_BAR,
	MODE_BAZ,
	MODE_QUX
};

/*
 * Names of members of structs are lower_case and separated by underscores.
 * Avoid typedef-ing types unless the type is intended to be used as an opaque
 * type.
 */
struct sample {
	int first_field;
	int second_field;
	Mode mode;
	State state;
	struct sample *next;
};

/*
 * Function names are lower_case. Opening braces on the next line.
 * Use gotos so that there is only one exit point for a given function.
 */
int sample_equal(struct sample *self, struct sample *other)
{
	int ret = 0;
	/* Local variables are lower_case and separated by underscores. */
	if (self == NULL && other == NULL) {
		ret = 1;
		goto out;
	}

	if (self == NULL || other == NULL) {
		goto out
	}

	/*
	 * For statements that span multiple lines, use spaces for alignment
	 * only.
	 */
	if (self->first_field == other->first_field &&
	    self->second_field == other->second_field &&
	    self->state == other->state &&
	    self->mode == other->mode &&
	    self->next == other->next) {
		ret = true;
	}
out:
	return ret;
}

/*
 * For function declarations that span multiple lines, indent them
 * "substantially to the right."
 */
struct sample *sample_new(int first_field, int second_field, int mode,
	                              int state, struct sample *next)
{
	struct sample *sample = (struct sample *) malloc(sizeof(*sample));
	if (sample == NULL) {
		sample = NULL;
		goto out;
	}

	memset(sample, 0, sizeof(sample));
	sample->first_field = first_field;
	sample->second_field = second_field;
	sample->mode = mode;
	sample->state = state;
	sample->next = next;
out:
	return sample;
}

struct sample *sample_clone(struct sample *sample)
{
	if (sample == NULL) {
		return NULL;
	}
	/*
	 * For function calls that span multiple lines, align them to the
	 * right.
	 */
	return sample_new(sample->first_field, sample->second_field,
		          sample->mode, sample->state, sample->next);
}

/*
 * For function declarations (and function calls) where you cannot fit
 * the parameters with the first after the opening parentheses, then align
 * the parameters indented four spaces on the next line:
 */
static void sample_do_something_with_a_long_name(
	                struct sample *sample, int parameter_with_a_long_name,
		        int another_parameter, int another_parameter)
{
	if (sample == NULL) {
		goto out;
	}

	/*
	 * else and else if comes after the previous closing brace and not on
	 * the next line.
	 */
	int local_variable;
	if (parameter_with_a_long_name == MODE_FOO) {
		local_variable = 1;
	} else {
		local_variable = 0;
	}
	sample->first_parameter += another_parameter;
	sample->second_parameter |= local_variable;
out:
	return;
}
