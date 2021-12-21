#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int pl1, pl2, bot1_1, bot1_2, temp, res = 0, percent, pl_money = 300000-30000, bot_money = 300000-30000, betting_sum = 60000, betting_money = 30000, cnt = 1;

char card[21][21]={}, pl_res[20], bot_res[20], pl_decide[20], bot_decide[20], thanks_38[20] = "삼팔광땡", thanks_1318[20] = "광땡",thanks_10[20] = "10땡", thanks_9[20] = "9땡", thanks_8[20] = "8땡", thanks_7[20] = "7땡", thanks_6[20] = "6땡", thanks_5[20] = "5땡", thanks_4[20] = "4땡", thanks_3[20] = "3땡", thanks_2[20] = "2땡", thanks_1[20] = "1땡", ali[20] = "알리", doksa[20] = "독사", bbing_9[20] = "구삥", bbing_jang[20] = "장삥", jangsa[20] = "장사", sae_6[20] = "세륙", gabo[20] = "갑오", end_8[20] = "8끗", end_7[20] = "7끗", end_6[20] = "6끗", end_5[20] = "5끗", end_4[20] = "4끗", end_3[20] = "3끗", end_2[20] = "2끗", end_1[20] = "1끗", mangtong[20] = "망통", thanks_jabi[20] = "땡잡이", gusa[20] = "구사", stupid_gusa[20] = "멍텅구리구사", armhang[20] = "암행어사", Die[20] = "다이", Check[20] = "체크", Bbing[20] = "삥", Call[20] = "콜", Ddadang[20] = "따당", Half[20] = "하프", All_in[20] = "올인", Blank[20] = {};

//player win: 225, bot win: 606, regame: 202(구사), 913(카드 같을 때)
//기본베팅금 : 30000

void rule() {
    printf("기본 룰 설명\n\n- 섯다는 플레이어 당 두 장의 패를 받아 상대와 족보를 비교하는 베팅게임입니다. \n\n\n베팅 방식\n\n- 올인 : 남은 돈을 전부 베팅합니다.\n- 하프 : 판돈의 절반을 베팅합니다\n- 따당 : 상대가 베팅한 금액의 절반을 베팅합니다.\n- 콜 : 상대가 베팅한 금액만큼 베팅하고 게임을 끝내길 요청합니다.\n- 삥 : 기본 베팅금만큼 베팅합니다.\n- 체크 : 베팅을 하지 않고 상대에게 턴을 넘깁니다.\n- 다이 : 게임을 포기합니다.\n\n\n\n기본 베팅금 30000원은 매 판 자동으로 빠져나갑니다. \n\n");
}

void help() {
	printf("┌───────────────────────────────────────────────────────────────────────┐\n");
	printf("│ 족보 도우미								│\n");
	printf("│ 			5. 독사			10. 갑오		│\n");
	printf("│ 1. 삼팔광땡		6. 구삥			11. 끗, 망통		│\n");
	printf("│ 2. 광땡		7. 장삥			 * 구사			│\n");
	printf("│ 3. 땡			8. 장사			 * 땡잡이		│\n");
	printf("│ 4. 알리		9. 세륙			 * 암행어사		│\n");
	printf("│-----------------------------------------------------------------------│\n");
	printf("│ * 구사 : 게임 재시작   * 땡잡이 : 1~9땡 잡기   * 암행어사 : 장땡 잡기	│\n");
	printf("└───────────────────────────────────────────────────────────────────────┘\n");

}

void start() {
    srand(time(NULL));
	pl1 = rand()%20+1;
	pl2 = rand()%20+1;
	bot1_1 = rand()%20+1;
	bot1_2 = rand()%20+1;

	while(pl1 == pl2){
		pl2 = rand()%20+1;
	}
	while(pl1 == bot1_1 || pl2 == bot1_1){
		bot1_1 = rand()%20+1;
	}
	while(pl1 == bot1_2 || pl2 == bot1_2 || bot1_1 == bot1_2){
		bot1_2 = rand()%20+1;
	}
}

void card_setting() {
    if (pl1 > pl2) {
        temp = pl1;
        pl1 = pl2;
        pl2 = temp;
    }
    if (bot1_1 > bot1_2) {
        temp = bot1_1;
        bot1_1 = bot1_2;
        bot1_2 = temp;
    }

	//갑오~망통 ; 19~28
	for(int i=1; i<=20; i++) {
		for(int j=1; j<=20; j++) {
			switch((i+j)%10) {
				case 9: card[i][j] = 19; break;
				case 8: card[i][j] = 20; break;
				case 7: card[i][j] = 21; break;
				case 6: card[i][j] = 22; break;
				case 5: card[i][j] = 23; break;
				case 4: card[i][j] = 24; break;
				case 3: card[i][j] = 25; break;
				case 2: card[i][j] = 26; break;
				case 1: card[i][j] = 27; break;
				case 0: card[i][j] = 28; break;
				default: break;
			}
		}
	}

    //땡
	for(int i=1; i<=20; i++) {
		for(int j=1; j<=20; j++) {
			if(i == j%10) card[i][j] = i;
		}
	}

	//삼팔광땡
	card[3][8] = 1;

	//광땡
	card[1][3] = 2;
	card[1][8] = 2;

	//알리
	card[1][2] = 13;
	card[1][12] = 13;
	card[2][11] = 13;
	card[11][12] = 13;

	//독사
	card[1][4] = 14;
	card[1][14] = 14;
	card[4][11] = 14;
	card[11][14] = 14;

	//구삥
	card[1][9] = 15;
	card[1][19] = 15;
	card[9][11] = 15;
	card[11][19] = 15;

	//장삥
	card[1][10] = 16;
	card[1][20] = 16;
	card[10][11] = 16;
	card[11][20] = 16;

	//장사
	card[4][10] = 17;
	card[4][20] = 17;
	card[10][14] = 17;
	card[14][20] = 17;

	//세륙
	card[4][6] = 18;
	card[4][16] = 18;
	card[6][14] = 18;
	card[14][16] = 18;

	//땡잡이
	card[3][7] = 30;
	card[3][17] = 30;
	card[7][13] = 30;
	card[13][17] = 30;

	//구사
	card[4][19] = 31;
	card[9][14] = 31;
	card[14][19] = 31;

	//멍텅구리 구사
	card[4][9] = 32;

	//암행어사
	card[4][7] = 33;


	//패 결과
	//player
	if (card[pl1][pl2] == 1)
		strcpy(pl_res, thanks_38);
	else if (card[pl1][pl2] == 2)
		strcpy(pl_res, thanks_1318);
	else if (card[pl1][pl2] == 3)
		strcpy(pl_res, thanks_10);
	else if (card[pl1][pl2] == 4)
		strcpy(pl_res, thanks_9);
	else if (card[pl1][pl2] == 5)
		strcpy(pl_res, thanks_8);
	else if (card[pl1][pl2] == 6)
		strcpy(pl_res, thanks_7);
	else if (card[pl1][pl2] == 7)
		strcpy(pl_res, thanks_6);
	else if (card[pl1][pl2] == 8)
		strcpy(pl_res, thanks_5);
	else if (card[pl1][pl2] == 9)
		strcpy(pl_res, thanks_4);
	else if (card[pl1][pl2] == 10)
		strcpy(pl_res, thanks_3);
	else if (card[pl1][pl2] == 11)
		strcpy(pl_res, thanks_2);
	else if (card[pl1][pl2] == 12)
		strcpy(pl_res, thanks_1);
	else if (card[pl1][pl2] == 13)
		strcpy(pl_res, ali);
	else if (card[pl1][pl2] == 14)
		strcpy(pl_res, doksa);
	else if (card[pl1][pl2] == 15)
		strcpy(pl_res, bbing_9);
	else if (card[pl1][pl2] == 16)
		strcpy(pl_res, bbing_jang);
	else if (card[pl1][pl2] == 17)
		strcpy(pl_res, jangsa);
	else if (card[pl1][pl2] == 18)
		strcpy(pl_res, sae_6);
	else if (card[pl1][pl2] == 19)
		strcpy(pl_res, gabo);
	else if (card[pl1][pl2] == 20)
		strcpy(pl_res, end_8);
	else if (card[pl1][pl2] == 21)
		strcpy(pl_res, end_7);
	else if (card[pl1][pl2] == 22)
		strcpy(pl_res, end_6);
	else if (card[pl1][pl2] == 23)
		strcpy(pl_res, end_5);
	else if (card[pl1][pl2] == 24)
		strcpy(pl_res, end_4);
	else if (card[pl1][pl2] == 25)
		strcpy(pl_res, end_3);
	else if (card[pl1][pl2] == 26)
		strcpy(pl_res, end_2);
	else if (card[pl1][pl2] == 27)
		strcpy(pl_res, end_1);
	else if (card[pl1][pl2] == 28)
		strcpy(pl_res, mangtong);
	else if (card[pl1][pl2] == 30)
		strcpy(pl_res, thanks_jabi);
	else if (card[pl1][pl2] == 31)
		strcpy(pl_res, gusa);
	else if (card[pl1][pl2] == 32)
		strcpy(pl_res, stupid_gusa);
	else if (card[pl1][pl2] == 33)
		strcpy(pl_res, armhang);
	//bot
	if (card[bot1_1][bot1_2] == 1)
		strcpy(bot_res, thanks_38);
	else if (card[bot1_1][bot1_2] == 2)
		strcpy(bot_res, thanks_1318);
	else if (card[bot1_1][bot1_2] == 3)
		strcpy(bot_res, thanks_10);
	else if (card[bot1_1][bot1_2] == 4)
		strcpy(bot_res, thanks_9);
	else if (card[bot1_1][bot1_2] == 5)
		strcpy(bot_res, thanks_8);
	else if (card[bot1_1][bot1_2] == 6)
		strcpy(bot_res, thanks_7);
	else if (card[bot1_1][bot1_2] == 7)
		strcpy(bot_res, thanks_6);
	else if (card[bot1_1][bot1_2] == 8)
		strcpy(bot_res, thanks_5);
	else if (card[bot1_1][bot1_2] == 9)
		strcpy(bot_res, thanks_4);
	else if (card[bot1_1][bot1_2] == 10)
		strcpy(bot_res, thanks_3);
	else if (card[bot1_1][bot1_2] == 11)
		strcpy(bot_res, thanks_2);
	else if (card[bot1_1][bot1_2] == 12)
		strcpy(bot_res, thanks_1);
	else if (card[bot1_1][bot1_2] == 13)
		strcpy(bot_res, ali);
	else if (card[bot1_1][bot1_2] == 14)
		strcpy(bot_res, doksa);
	else if (card[bot1_1][bot1_2] == 15)
		strcpy(bot_res, bbing_9);
	else if (card[bot1_1][bot1_2] == 16)
		strcpy(bot_res, bbing_jang);
	else if (card[bot1_1][bot1_2] == 17)
		strcpy(bot_res, jangsa);
	else if (card[bot1_1][bot1_2] == 18)
		strcpy(bot_res, sae_6);
	else if (card[bot1_1][bot1_2] == 19)
		strcpy(bot_res, gabo);
	else if (card[bot1_1][bot1_2] == 20)
		strcpy(bot_res, end_8);
	else if (card[bot1_1][bot1_2] == 21)
		strcpy(bot_res, end_7);
	else if (card[bot1_1][bot1_2] == 22)
		strcpy(bot_res, end_6);
	else if (card[bot1_1][bot1_2] == 23)
		strcpy(bot_res, end_5);
	else if (card[bot1_1][bot1_2] == 24)
		strcpy(bot_res, end_4);
	else if (card[bot1_1][bot1_2] == 25)
		strcpy(bot_res, end_3);
	else if (card[bot1_1][bot1_2] == 26)
		strcpy(bot_res, end_2);
	else if (card[bot1_1][bot1_2] == 27)
		strcpy(bot_res, end_1);
	else if (card[bot1_1][bot1_2] == 28)
		strcpy(bot_res, mangtong);
	else if (card[bot1_1][bot1_2] == 30)
		strcpy(bot_res, thanks_jabi);
	else if (card[bot1_1][bot1_2] == 31)
		strcpy(bot_res, gusa);
	else if (card[bot1_1][bot1_2] == 32)
		strcpy(bot_res, stupid_gusa);
	else if (card[bot1_1][bot1_2] == 33)
		strcpy(bot_res, armhang);
}

void all_in() {
    betting_money = pl_money;
    pl_money = 0;
    betting_sum += betting_money;
    printf("\n올인했습니다. \n\n");
}

void call() {
    if (pl_money >= betting_money) {
        pl_money -= betting_money;
        betting_sum += betting_money;
    }
    else {
        strcpy(pl_decide, All_in);
        all_in();
    }
}

void bbing() {
	if (pl_money >= betting_money) {
        pl_money -= betting_money;
        betting_sum += betting_money;
	}
	else {
        strcpy(pl_decide, All_in);
        all_in();
    }
}

void die() {
	res = 606;
	printf("게임을 포기했습니다. \n");
	betting_money = 0;
}

void check() {

}

void ddadang() {
	if (pl_money >= 2*betting_money) {
        betting_money *= 2;
        pl_money -= betting_money;
        betting_sum += betting_money;
	}
	else {
        strcpy(pl_decide, All_in);
        all_in();
    }
}

void half() {
    if (pl_money >= 0.5*betting_sum) {
        betting_money = 0.5*betting_sum;
        pl_money -= betting_money;
        betting_sum += betting_money;
    }
    else {
        strcpy(pl_decide, All_in);
        all_in();
    }
}

void bot_all_in() {
    betting_money = bot_money;
    bot_money = 0;
    betting_sum += betting_money;
    printf("상대가 올인했습니다. \n");
}

void bot_call() {
    if (bot_money >= betting_money) {
        bot_money -= betting_money;
        betting_sum += betting_money;
        printf("상대가 콜을 했습니다. \n");
    }
    else {
        strcpy(bot_decide, All_in);
        bot_all_in();
    }
}

void bot_die() {
	res = 225;
	printf("상대가 게임을 포기했습니다. \n");
	betting_money = 0;
}

void bot_ddadang() {
    if (bot_money >= 2*betting_money) {
        betting_money *= 2;
        bot_money -= betting_money;
        betting_sum += betting_money;
        printf("상대가 따당을 했습니다. \n");
	}
	else {
        strcpy(bot_decide, All_in);
        bot_all_in();
	}
}

void bot_half() {
    if (bot_money >= 0.5*betting_sum) {
        betting_money = 0.5*betting_sum;
        bot_money -= betting_money;
        betting_sum += betting_money;
        printf("상대가 하프를 했습니다. \n");
    }
    else {
        strcpy(bot_decide, All_in);
        bot_all_in();
    }
}

void bot_betting_input() {
    srand(time(NULL));
    percent = rand()%100;
    if (card[bot1_1][bot1_2] == 1) { // 삼팔광땡
        if (percent < 90) { // 하프 : 90%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 90 && percent < 98) { // 따당 : 8%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 98 && percent < 99) { // 콜 : 1%
            strcpy(bot_decide, Call);
        }
        else { // 올인 : 1%
            strcpy(bot_decide, All_in);
        }
    }
    else if (card[bot1_1][bot1_2] == 2) { // 광땡
        if (percent < 80) { // 하프 : 80%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 80 && percent < 95) { // 따당 : 15%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 95 && percent < 98) { // 콜 : 3%
            strcpy(bot_decide, Call);
        }
        else if (percent >= 98 && percent < 99) { // 다이 : 1%
            strcpy(bot_decide, Die);
        }
        else { // 올인 : 1%
            strcpy(bot_decide, All_in);
        }
    }
    else if (card[bot1_1][bot1_2] > 2 && card[bot1_1][bot1_2] < 8) { // 10땡~6땡
        if (percent < 75) { // 하프 : 75%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 75 && percent < 90) { // 따당 : 15%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 90 && percent < 97) { // 콜 : 7%
            strcpy(bot_decide, Call);
        }
        else if (percent >= 97 && percent < 99) { // 다이 : 2%
            strcpy(bot_decide, Die);
        }
        else { // 올인 : 1%
            strcpy(bot_decide, All_in);
        }
    }
    else if (card[bot1_1][bot1_2] > 7 && card[bot1_1][bot1_2] < 13) { // 5땡~1땡
        if (percent < 70) { // 하프 : 70%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 70 && percent < 90) { // 따당 : 20%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 90 && percent < 97) { // 콜 : 7%
            strcpy(bot_decide, Call);
        }
        else if (percent >= 97 && percent < 99) { // 다이 : 2%
            strcpy(bot_decide, Die);
        }
        else { // 올인 : 1%
            strcpy(bot_decide, All_in);
        }
    }
    else if (card[bot1_1][bot1_2] > 12 && card[bot1_1][bot1_2] < 20) { // 알리~갑오
        if (percent < 60) { // 하프 : 60%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 60 && percent < 75) { // 따당 : 15%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 75 && percent < 95) { // 콜 : 20%
            strcpy(bot_decide, Call);
        }
        else if (percent >= 95 && percent < 99) { // 다이 : 4%
            strcpy(bot_decide, Die);
        }
        else { // 올인 : 1%
            strcpy(bot_decide, All_in);
        }
    }
    else if (card[bot1_1][bot1_2] > 19 && card[bot1_1][bot1_2] <29) { // 8끗~망통
        if (percent < 45) { // 하프 : 45%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 45 && percent < 55) { // 따당 : 10%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 55 && percent < 79) { // 콜 : 24%
            strcpy(bot_decide, Call);
        }
        else if (percent >= 79 && percent < 99) { // 다이 : 20%
            strcpy(bot_decide, Die);
        }
        else { // 올인 : 1%
            strcpy(bot_decide, All_in);
        }
    }
    else if (card[bot1_1][bot1_2] == 30) { // 땡잡이
        if (percent < 50) { // 하프 : 50%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 50 && percent < 70) { // 따당 : 20%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 70 && percent < 90) { // 콜 : 20%
            strcpy(bot_decide, Call);
        }
        else if (percent >= 90 && percent < 99) { // 다이 : 9%
            strcpy(bot_decide, Die);
        }
        else { // 올인 : 1%
            strcpy(bot_decide, All_in);
        }
    }
    else if (card[bot1_1][bot1_2] == 33) { // 암행어사
        if (percent < 30) { // 하프 : 30%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 30 && percent < 60) { // 따당 : 30%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 60 && percent < 85) { // 콜 : 25%
            strcpy(bot_decide, Call);
        }
        else if (percent >= 85 && percent < 99) { // 다이 : 14%
            strcpy(bot_decide, Die);
        }
        else { // 올인 : 1%
            strcpy(bot_decide, All_in);
        }
    }
    else { // 구사, 멍텅구리 구사
        if (percent < 60) { // 하프 : 60%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 60 && percent < 75) { // 따당 : 15%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 75 && percent < 98) { // 콜 : 23%
            strcpy(bot_decide, Call);
        }
        else if (percent <= 98 && percent < 99) { // 다이 : 1%
            strcpy(bot_decide, Die);
        }
        else { // 올인 : 1%
            strcpy(bot_decide, All_in);
        }
    }
}

void bot_betting() {
    if (card[bot1_1][bot1_2] == 1) { // 삼팔광땡
        if (percent < 90) { // 하프 : 90%
            bot_half();
        }
        else if (percent >= 90 && percent < 98) { // 따당 : 8%
            bot_ddadang();
        }
        else if (percent >= 98 && percent < 99) { // 콜 : 1%
            bot_call();
        }
        else { // 올인 : 1%
            bot_all_in();
        }
    }
    else if (card[bot1_1][bot1_2] == 2) { // 광땡
        if (percent < 80) { // 하프 : 80%
            bot_half();
        }
        else if (percent >= 80 && percent < 95) { // 따당 : 15%
            bot_ddadang();
        }
        else if (percent >= 95 && percent < 98) { // 콜 : 3%
            bot_call();
        }
        else if (percent >= 98 && percent < 99) { // 다이 : 1%
            bot_die();
        }
        else { // 올인 : 1%
            bot_all_in();
        }
    }
    else if (card[bot1_1][bot1_2] > 2 && card[bot1_1][bot1_2] < 8) { // 10땡~6땡
        if (percent < 75) { // 하프 : 75%
            bot_half();
        }
        else if (percent >= 75 && percent < 90) { // 따당 : 15%
            bot_ddadang();
        }
        else if (percent >= 90 && percent < 97) { // 콜 : 7%
            bot_call();
        }
        else if (percent >= 97 && percent < 99) { // 다이 : 2%
            bot_die();
        }
        else { // 올인 : 1%
            bot_all_in();
        }
    }
    else if (card[bot1_1][bot1_2] > 7 && card[bot1_1][bot1_2] < 13) { // 5땡~1땡
        if (percent < 70) { // 하프 : 70%
            bot_half();
        }
        else if (percent >= 70 && percent < 90) { // 따당 : 20%
            bot_ddadang();
        }
        else if (percent >= 90 && percent < 97) { // 콜 : 7%
            bot_call();
        }
        else if (percent >= 97 && percent < 99) { // 다이 : 2%
            bot_die();
        }
        else { // 올인 : 1%
            bot_all_in();
        }
    }
    else if (card[bot1_1][bot1_2] > 12 && card[bot1_1][bot1_2] < 20) { // 알리~갑오
        if (percent < 60) { // 하프 : 60%
            bot_half();
        }
        else if (percent >= 60 && percent < 75) { // 따당 : 15%
            bot_ddadang();
        }
        else if (percent >= 75 && percent < 95) { // 콜 : 20%
            bot_call();
        }
        else if (percent >= 95 && percent < 99) { // 다이 : 4%
            bot_die();
        }
        else { // 올인 : 1%
            bot_all_in();
        }
    }
    else if (card[bot1_1][bot1_2] > 19 && card[bot1_1][bot1_2] <29) { // 8끗~망통
        if (percent < 45) { // 하프 : 45%
            bot_half();
        }
        else if (percent >= 45 && percent < 55) { // 따당 : 10%
            bot_ddadang();
        }
        else if (percent >= 55 && percent < 79) { // 콜 : 24%
            bot_call();
        }
        else if (percent >= 79 && percent < 99) { // 다이 : 20%
            bot_die();
        }
        else { // 올인 : 1%
            bot_all_in();
        }
    }
    else if (card[bot1_1][bot1_2] == 30) { // 땡잡이
        if (percent < 50) { // 하프 : 50%
            bot_half();
        }
        else if (percent >= 50 && percent < 70) { // 따당 : 20%
            bot_ddadang();
        }
        else if (percent >= 70 && percent < 90) { // 콜 : 20%
            bot_call();
        }
        else if (percent >= 90 && percent < 99) { // 다이 : 9%
            bot_die();
        }
        else { // 올인 : 1%
            bot_all_in();
        }
    }
    else if (card[bot1_1][bot1_2] == 33) { // 암행어사
        if (percent < 30) { // 하프 : 30%
            bot_half();
        }
        else if (percent >= 30 && percent < 60) { // 따당 : 30%
            bot_ddadang();
        }
        else if (percent >= 60 && percent < 85) { // 콜 : 25%
            bot_call();
        }
        else if (percent >= 85 && percent < 99) { // 다이 : 14%
            bot_die();
        }
        else { // 올인 : 1%
            bot_all_in();
        }
    }
    else { // 구사, 멍텅구리 구사
        if (percent < 60) { // 하프 : 60%
            bot_half();
        }
        else if (percent >= 60 && percent < 75) { // 따당 : 15%
            bot_ddadang();
        }
        else if (percent >= 75 && percent < 98) { // 콜 : 23%
            bot_call();
        }
        else if (percent >= 98 && percent < 99) { // 다이 : 1%
            bot_die();
        }
        else { // 올인 : 1%
            bot_all_in();
        }
    }
}

void player_betting_input() {
    scanf("%s", &pl_decide);
    //puts(pl_decide);
}

void player_betting() {
    if (!strcmp(pl_decide, All_in)) {
        all_in();
    }
    else if (!strcmp(pl_decide, Call)) {
        call();
    }
    else if (!strcmp(pl_decide, Bbing)) {
        bbing();
    }
    else if (!strcmp(pl_decide, Die)) {
        die();
    }
    else if (!strcmp(pl_decide, Check)) {
        check();
    }
    else if (!strcmp(pl_decide, Ddadang)) {
        ddadang();
    }
    else if (!strcmp(pl_decide, Half)) {
        half();
    }
    else {
        printf("잘못 입력하였습니다. \n");
        player_betting_input();
        player_betting();
    }
}

void card_open() {
    printf("당신의 패는 %s입니다. \n", pl_res);
    help();
}

void betting() {
    while(1) {
        //player
        if (cnt == 1) {
            printf("\n당신의 턴입니다. \n\n");
            printf("\n남은 돈 : %d원\n상대 남은 돈 : %d원\n\n\n\n", pl_money, bot_money);
            while(1) {
                printf("할 수 있는 행동은 다음과 같습니다.\n\n");
                printf("- 하프\n- 삥\n- 체크\n- 다이\n\n");
                player_betting_input();
                if (!strcmp(pl_decide, Half) || !strcmp(pl_decide, Bbing) || !strcmp(pl_decide, Check) || !strcmp(pl_decide, Die)) {
                    break;
                }
                else {
                    printf("\n잘못 입력하였습니다. \n");
                }
            }
            player_betting();
            if (!strcmp(pl_decide, Check)) {
                printf("\n베팅한 금액 : 0원\n");
                printf("판돈 : %d원\n\n\n\n\n\n\n\n\n\n", betting_sum);
            }
            else {
                printf("\n베팅한 금액 : %d원\n", betting_money);
                printf("판돈 : %d원\n\n\n\n\n\n\n\n\n\n", betting_sum);
            }
            cnt++;
        }
        else if (!strcmp(bot_decide, All_in)) {
            printf("\n당신의 턴입니다. \n\n\n");
            printf("\n남은 돈 : %d원\n상대 남은 돈 : %d원\n\n\n\n\n", pl_money, bot_money);
            while(1) {
                printf("할 수 있는 행동은 다음과 같습니다.\n\n");
                printf("- 콜\n- 다이\n\n");
                player_betting_input();
                if (!strcmp(pl_decide, Call) || !strcmp(pl_decide, Die)) {
                    break;
                }
                else {
                    printf("\n잘못 입력하였습니다. \n");
                }
            }
            player_betting();
            printf("\n베팅한 금액 : %d원\n", betting_money);
            printf("판돈 : %d원\n\n\n\n\n\n\n\n\n\n", betting_sum);
        }
        else if (!strcmp(bot_decide, Call)) {
            printf("\n당신의 턴입니다. \n\n\n");
            printf("\n남은 돈 : %d원\n상대 남은 돈 : %d원\n\n\n\n\n", pl_money, bot_money);
            while(1) {
                printf("할 수 있는 행동은 다음과 같습니다.\n\n");
                printf("- 하프\n- 콜\n- 다이\n\n");
                player_betting_input();
                if(!strcmp(pl_decide, Half) || !strcmp(pl_decide, Call) || !strcmp(pl_decide, Die)) {
                    break;
                }
                else {
                    printf("\n잘못 입력하였습니다. \n");
                }
            }
            player_betting();
            printf("\n베팅한 금액 : %d원\n", betting_money);
            printf("판돈 : %d원\n\n\n\n\n\n\n\n\n\n", betting_sum);
        }
        else {
            printf("\n당신의 턴입니다. \n\n\n");
            printf("\n남은 돈 : %d원\n상대 남은 돈 : %d원\n\n\n\n\n", pl_money, bot_money);
            while(1) {
                printf("할 수 있는 행동은 다음과 같습니다.\n\n");
                printf("- 올인\n- 하프\n- 따당\n- 콜\n- 다이\n\n");
                player_betting_input();
                if(!strcmp(pl_decide, All_in) || !strcmp(pl_decide, Half) || !strcmp(pl_decide, Ddadang) || !strcmp(pl_decide, Call) || !strcmp(pl_decide, Die)) {
                    break;
                }
                else {
                    printf("\n잘못 입력하였습니다. \n");
                }
            }
            player_betting();
            printf("\n베팅한 금액 : %d원\n", betting_money);
            printf("판돈 : %d원\n\n\n\n\n\n\n\n\n\n", betting_sum);
        }

        //끝날 수 있는 경우
        if (!strcmp(pl_decide, Die) || !strcmp(bot_decide, All_in) || !strcmp(bot_decide, Call)) break;

        //bot
        if(!strcmp(pl_decide, All_in)) {
            while(1) {
                bot_betting_input();
                if(!strcmp(bot_decide, Call) || !strcmp(bot_decide, Die)) {
                    break;
                }
            }
            bot_betting();
            printf("\n상대가 베팅한 금액 : %d원\n", betting_money);
            printf("판돈 : %d원\n\n\n\n\n\n\n\n\n\n", betting_sum);
        }
        else if (!strcmp(pl_decide, Call)) {
            while (1) {
                bot_betting_input();
                if(!strcmp(bot_decide, Half) || !strcmp(bot_decide, Call) || !strcmp(bot_decide, Die)) {
                    break;
                }
            }
            bot_betting();
            printf("\n상대가 베팅한 금액 : %d원\n", betting_money);
            printf("판돈 : %d원\n\n\n\n\n\n\n\n\n\n", betting_sum);
        }
        else {
            while(1) {
                bot_betting_input();
                if (!strcmp(bot_decide, All_in) || !strcmp(bot_decide, Half) || !strcmp(bot_decide, Ddadang) || !strcmp(bot_decide, Call) || !strcmp(bot_decide, Die)) {
                    break;
                }
            }
            bot_betting();
            printf("\n상대가 베팅한 금액 : %d원\n", betting_money);
            printf("판돈 : %d원\n\n\n\n\n\n\n\n\n\n", betting_sum);
        }

        //끝날 수 있는 경우
        if (!strcmp(bot_decide, Die) || !strcmp(pl_decide, All_in) || !strcmp(pl_decide, Call)) break;
    }
}

void card_judge() {
	//삼팔광땡
	if (card[pl1][pl2] == 1)
        res = 225;
	else if (card[bot1_1][bot1_2] == 1) res = 606;

	//암행어사
	else if (card[pl1][pl2] == 33 && card[bot1_1][bot1_2] == 2)
		res = 225;
	else if (card[pl1][pl2] == 33 && card[bot1_1][bot1_2] != 2)
		card[pl1][pl2] = 27;
	else if (card[bot1_1][bot1_2] == 33 && card[pl1][pl2] == 2)
		res = 606;
	else if (card[bot1_1][bot1_2] == 33 && card[pl1][pl2] != 2)
		card[pl1][pl2] = 27;

	//땡잡이
	else if (card[pl1][pl2] == 30 && (3 < card[bot1_1][bot1_2] < 13))
		res == 225;
	else if (card[pl1][pl2] == 30 && !(3 < card[bot1_1][bot1_2] < 13))
		card[pl1][pl2] = 28;
	else if ((card[bot1_1][bot1_2] == 30 && (3 < card[pl1][pl2] < 13)))
		res == 606;
	else if (card[bot1_1][bot1_2] == 30 && (card[pl1][pl2] != 4 || card[pl1][pl2] != 5 || card[pl1][pl2] != 6 || card[pl1][pl2] != 7 || card[pl1][pl2] != 8 || card[pl1][pl2] != 9 || card[pl1][pl2] != 10 || card[pl1][pl2] != 11 || card[pl1][pl2] != 12))
		card[bot1_1][bot1_2] = 28;

	//멍텅구리 구사
	else if (card[pl1][pl2] == 32 && card[bot1_1][bot1_2] > 2)
		res = 202;
	else if (card[pl1][pl2] == 32 && card[bot1_1][bot1_2] <= 2) {}
	else if (card[bot1_1][bot1_2] == 32 && card[pl1][pl2] > 2)
		res = 202;
	else if (card[bot1_1][bot1_2] == 32 && card[pl1][pl2] <= 2) {}

	//구사
	else if (card[pl1][pl2] == 31 && card[bot1_1][bot1_2] > 12)
		res = 202;
	else if (card[pl1][pl2] == 31 && card[bot1_1][bot1_2] <= 12) {}
	else if (card[bot1_1][bot1_2] == 31 && card[pl1][pl2] > 12)
		res = 202;
	else if (card[bot1_1][bot1_2] == 31 && card[pl1][pl2] <= 12) {}

	//나머지
	if (card[pl1][pl2] < card[bot1_1][bot1_2])
		res = 225;
	else if (card[bot1_1][bot1_2] < card[pl1][pl2])
		res = 606;
    else if (card[pl1][pl2] == card[bot1_1][bot1_2])
        res = 913;
}

void result() {
    if (res == 225) {
        printf("나의 패 : %s, 상대 패 : %s\n\n", pl_res, bot_res);
        printf("승리 \n");
        help();
        pl_money += betting_sum;
        printf("\n남은 돈 : %d원\n상대 남은 돈 : %d원\n\n\n\n\n", pl_money, bot_money);
        cnt = 1;
        betting_money = 30000;
        betting_sum = 60000;
        pl_money -= 30000;
        bot_money -= 30000;
        strcpy(pl_decide, Blank);
        strcpy(bot_decide, Blank);
    }
    else if (res == 606) {
        printf("나의 패 : %s, 상대 패 : %s\n\n", pl_res, bot_res);
        printf("패배 \n");
        help();
        bot_money += betting_sum;
        printf("\n남은 돈 : %d원\n상대 남은 돈 : %d원\n\n\n\n\n", pl_money, bot_money);
        cnt = 1;
        betting_money = 30000;
        betting_sum = 60000;
        pl_money -= 30000;
        bot_money -= 30000;
        strcpy(pl_decide, Blank);
        strcpy(bot_decide, Blank);
    }
    else if (res == 202) {
        printf("나의 패 : %s, 상대 패 : %s\n\n", pl_res, bot_res);
        printf("재경기 (%s : %s)\n", !strcmp(pl_res, gusa) || !strcmp(pl_res, stupid_gusa)? "나": "상대", !strcmp(pl_res, gusa) || !strcmp(bot_res, gusa)? "구사": "멍텅구리구사");
        printf("판돈은 그대로 유지됩니다. \n");
        printf("\n\n남은 돈 : %d원\n상대 남은 돈 : %d원\n\n\n\n\n", pl_money, bot_money);
        cnt = 1;
        betting_money = 30000;
        strcpy(pl_decide, Blank);
        strcpy(bot_decide, Blank);
    }
    else if (res == 913) {
        printf("나의 패 : %s, 상대 패 : %s\n\n", pl_res, bot_res);
        printf("재경기\n");
        printf("판돈은 그대로 유지됩니다. \n");
        printf("\n\n남은 돈 : %d원\n상대 남은 돈 : %d원\n\n\n\n\n", pl_money, bot_money);
        cnt = 1;
        betting_money = 30000;
        strcpy(pl_decide, Blank);
        strcpy(bot_decide, Blank);
    }
    else {
        printf("이거 나오면 망한건데");
    }
}

int main() {
    rule();
    while(!(pl_money < 0 || bot_money < 0)) {
        start();
        card_setting();
        card_open();
        card_judge();
        betting();
        result();
    }
    if (pl_money <= 0) {
        printf("\n\n\n\n\n\n최종 패배\n\n\n\n\n\n");
        printf("");
    }
    else if (bot_money <= 0) {
        printf("\n\n\n\n\n\n최종 승리\n\n\n\n\n\n");
        printf("");
    }
    else {
        printf("엥 이거 나오면 망한건데");
    }




    return 0;
}
