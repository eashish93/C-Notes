/** Consider the code **/

/** Example - 1 **/

while(scanf("%d", &n),  n) { 		/* comma in while loop means that both are executed in every respect */
		/* Note that scanf("%d", &n) gives positive value whether n is zero or not */
		/* or while(scanf("%d", &n) && n != 0) {... } */
		/* or while(1) {scanf("%d", &n); if(n == 0) break; ...}*/
		/* or while(scanf("%d", &n)) {if(n == 0) break; ...} */

// Note it doesn't mean that `,` operator is equivalent to &&. In above, you can use any because they generate the same result. But this
// is not always the case. The difference is that -- if `comma` operator is used then both are evaluated while in `and` operator 
// last one is evaluated only if first one is true
// So this means that you can exchange them with && if is used for comparison only.
// But note, it is better not to use them for comparison, it merely creates a confusion

/** Example - 2**/
if (something) dothis(), dothat(), x++;
 // this is equivalent to
if (something) { dothis(); dothat(); x++; }


/** Example - 3 **/


if(x = n / d, n % d) // == (first x = n/d; then if(n%d))
    printf("Remainder not zero, x + 1 = %d", (x + 1));
  else
    printf("Remainder is zero,  x - 1 = %d", (x - 1));