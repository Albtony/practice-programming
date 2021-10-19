// Codeforces

/*
PizzaForces is Petya's favorite pizzeria. PizzaForces makes and sells pizzas of three sizes: small pizzas consist of 6 slices, 
medium ones consist of 8 slices, and large pizzas consist of 10 slices each. Baking them takes 15, 20 and 25 minutes, respectively.

Petya's birthday is today, and n of his friends will come, so he decided to make an order from his favorite pizzeria. Petya wants 
to order so much pizza that each of his friends gets at least one slice of pizza. The cooking time of the order is the total baking 
time of all the pizzas in the order.

Your task is to determine the minimum number of minutes that is needed to make pizzas containing at least n slices in total. For 
example:

if 12 friends come to Petya's birthday, he has to order pizzas containing at least 12 slices in total. He can order two small 
pizzas, containing exactly 12 slices, and the time to bake them is 30 minutes;
if 15 friends come to Petya's birthday, he has to order pizzas containing at least 15 slices in total. He can order a small pizza 
and a large pizza, containing 16 slices, and the time to bake them is 40 minutes;
if 300 friends come to Petya's birthday, he has to order pizzas containing at least 300 slices in total. He can order 15 small 
pizzas, 10 medium pizzas and 13 large pizzas, in total they contain 15⋅6+10⋅8+13⋅10=300 slices, and the total time to bake them is 
15⋅15+10⋅20+13⋅25=750 minutes;
if only one friend comes to Petya's birthday, he can order a small pizza, and the time to bake it is 15 minutes.
*/

/*
Input
The first line contains a single integer t (1≤t≤104) — the number of testcases.

Each testcase consists of a single line that contains a single integer n (1≤n≤1016) — the number of Petya's friends.

Output
For each testcase, print one integer — the minimum number of minutes that is needed to bake pizzas containing at least n 
slices in total.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase;
    long long fren, pizza, time;
    cin >> testcase;
    while(testcase--){
        cin >> fren;
        pizza = fren;
        while(pizza < 6 || pizza % 2 != 0)
            pizza += 1;
        cout << pizza / 2 * 5 << "\n";
    }

    return 0;
}

/*
Again credit to Tourist who ofc have much better solution than me

So in this problem we need to find the minimum time to cook at least "fren" number of pizza
we can cook 6, 8, 10 pizza each time for 15, 20, 25 respectively

if fren < 6
    time = 15, cuz we can only cook a minimum of 6 pizza which takes 15 minutes
if fren = 7
    time = 20, cuz we cook 8 to feed 7 fren, excess is ok

if we look at number of pizza we can cook and its time respectively, we can see
that for each 2 pizza, the time increases 5 min

also 6, 8, 10 can make any even number given number is atleast >= 6
and cannot make any odd number

thats why if we get odd number of fren, we increment it by one so it became odds
and find the time with 2 pizza/minute rate

and if we get fren < 6, we increment it until 6 cuz 6 is the minimum pizza we can cook
hence time = 6 / 2 * 5 = 15 which is in congruence with 2 pizza/minute rate
*/