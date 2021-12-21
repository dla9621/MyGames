#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int pl1, pl2, bot1_1, bot1_2, temp, res = 0, percent, pl_money = 300000-30000, bot_money = 300000-30000, betting_sum = 60000, betting_money = 30000, cnt = 1;

char card[21][21]={}, pl_res[20], bot_res[20], pl_decide[20], bot_decide[20], thanks_38[20] = "���ȱ���", thanks_1318[20] = "����",thanks_10[20] = "10��", thanks_9[20] = "9��", thanks_8[20] = "8��", thanks_7[20] = "7��", thanks_6[20] = "6��", thanks_5[20] = "5��", thanks_4[20] = "4��", thanks_3[20] = "3��", thanks_2[20] = "2��", thanks_1[20] = "1��", ali[20] = "�˸�", doksa[20] = "����", bbing_9[20] = "����", bbing_jang[20] = "���", jangsa[20] = "���", sae_6[20] = "����", gabo[20] = "����", end_8[20] = "8��", end_7[20] = "7��", end_6[20] = "6��", end_5[20] = "5��", end_4[20] = "4��", end_3[20] = "3��", end_2[20] = "2��", end_1[20] = "1��", mangtong[20] = "����", thanks_jabi[20] = "������", gusa[20] = "����", stupid_gusa[20] = "���ֱ�������", armhang[20] = "������", Die[20] = "����", Check[20] = "üũ", Bbing[20] = "��", Call[20] = "��", Ddadang[20] = "����", Half[20] = "����", All_in[20] = "����", Blank[20] = {};

//player win: 225, bot win: 606, regame: 202(����), 913(ī�� ���� ��)
//�⺻���ñ� : 30000

void rule() {
    printf("�⺻ �� ����\n\n- ���ٴ� �÷��̾� �� �� ���� �и� �޾� ���� ������ ���ϴ� ���ð����Դϴ�. \n\n\n���� ���\n\n- ���� : ���� ���� ���� �����մϴ�.\n- ���� : �ǵ��� ������ �����մϴ�\n- ���� : ��밡 ������ �ݾ��� ������ �����մϴ�.\n- �� : ��밡 ������ �ݾ׸�ŭ �����ϰ� ������ ������ ��û�մϴ�.\n- �� : �⺻ ���ñݸ�ŭ �����մϴ�.\n- üũ : ������ ���� �ʰ� ��뿡�� ���� �ѱ�ϴ�.\n- ���� : ������ �����մϴ�.\n\n\n\n�⺻ ���ñ� 30000���� �� �� �ڵ����� ���������ϴ�. \n\n");
}

void help() {
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("�� ���� �����								��\n");
	printf("�� 			5. ����			10. ����		��\n");
	printf("�� 1. ���ȱ���		6. ����			11. ��, ����		��\n");
	printf("�� 2. ����		7. ���			 * ����			��\n");
	printf("�� 3. ��			8. ���			 * ������		��\n");
	printf("�� 4. �˸�		9. ����			 * ������		��\n");
	printf("��-----------------------------------------------------------------------��\n");
	printf("�� * ���� : ���� �����   * ������ : 1~9�� ���   * ������ : �嶯 ���	��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������\n");

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

	//����~���� ; 19~28
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

    //��
	for(int i=1; i<=20; i++) {
		for(int j=1; j<=20; j++) {
			if(i == j%10) card[i][j] = i;
		}
	}

	//���ȱ���
	card[3][8] = 1;

	//����
	card[1][3] = 2;
	card[1][8] = 2;

	//�˸�
	card[1][2] = 13;
	card[1][12] = 13;
	card[2][11] = 13;
	card[11][12] = 13;

	//����
	card[1][4] = 14;
	card[1][14] = 14;
	card[4][11] = 14;
	card[11][14] = 14;

	//����
	card[1][9] = 15;
	card[1][19] = 15;
	card[9][11] = 15;
	card[11][19] = 15;

	//���
	card[1][10] = 16;
	card[1][20] = 16;
	card[10][11] = 16;
	card[11][20] = 16;

	//���
	card[4][10] = 17;
	card[4][20] = 17;
	card[10][14] = 17;
	card[14][20] = 17;

	//����
	card[4][6] = 18;
	card[4][16] = 18;
	card[6][14] = 18;
	card[14][16] = 18;

	//������
	card[3][7] = 30;
	card[3][17] = 30;
	card[7][13] = 30;
	card[13][17] = 30;

	//����
	card[4][19] = 31;
	card[9][14] = 31;
	card[14][19] = 31;

	//���ֱ��� ����
	card[4][9] = 32;

	//������
	card[4][7] = 33;


	//�� ���
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
    printf("\n�����߽��ϴ�. \n\n");
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
	printf("������ �����߽��ϴ�. \n");
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
    printf("��밡 �����߽��ϴ�. \n");
}

void bot_call() {
    if (bot_money >= betting_money) {
        bot_money -= betting_money;
        betting_sum += betting_money;
        printf("��밡 ���� �߽��ϴ�. \n");
    }
    else {
        strcpy(bot_decide, All_in);
        bot_all_in();
    }
}

void bot_die() {
	res = 225;
	printf("��밡 ������ �����߽��ϴ�. \n");
	betting_money = 0;
}

void bot_ddadang() {
    if (bot_money >= 2*betting_money) {
        betting_money *= 2;
        bot_money -= betting_money;
        betting_sum += betting_money;
        printf("��밡 ������ �߽��ϴ�. \n");
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
        printf("��밡 ������ �߽��ϴ�. \n");
    }
    else {
        strcpy(bot_decide, All_in);
        bot_all_in();
    }
}

void bot_betting_input() {
    srand(time(NULL));
    percent = rand()%100;
    if (card[bot1_1][bot1_2] == 1) { // ���ȱ���
        if (percent < 90) { // ���� : 90%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 90 && percent < 98) { // ���� : 8%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 98 && percent < 99) { // �� : 1%
            strcpy(bot_decide, Call);
        }
        else { // ���� : 1%
            strcpy(bot_decide, All_in);
        }
    }
    else if (card[bot1_1][bot1_2] == 2) { // ����
        if (percent < 80) { // ���� : 80%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 80 && percent < 95) { // ���� : 15%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 95 && percent < 98) { // �� : 3%
            strcpy(bot_decide, Call);
        }
        else if (percent >= 98 && percent < 99) { // ���� : 1%
            strcpy(bot_decide, Die);
        }
        else { // ���� : 1%
            strcpy(bot_decide, All_in);
        }
    }
    else if (card[bot1_1][bot1_2] > 2 && card[bot1_1][bot1_2] < 8) { // 10��~6��
        if (percent < 75) { // ���� : 75%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 75 && percent < 90) { // ���� : 15%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 90 && percent < 97) { // �� : 7%
            strcpy(bot_decide, Call);
        }
        else if (percent >= 97 && percent < 99) { // ���� : 2%
            strcpy(bot_decide, Die);
        }
        else { // ���� : 1%
            strcpy(bot_decide, All_in);
        }
    }
    else if (card[bot1_1][bot1_2] > 7 && card[bot1_1][bot1_2] < 13) { // 5��~1��
        if (percent < 70) { // ���� : 70%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 70 && percent < 90) { // ���� : 20%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 90 && percent < 97) { // �� : 7%
            strcpy(bot_decide, Call);
        }
        else if (percent >= 97 && percent < 99) { // ���� : 2%
            strcpy(bot_decide, Die);
        }
        else { // ���� : 1%
            strcpy(bot_decide, All_in);
        }
    }
    else if (card[bot1_1][bot1_2] > 12 && card[bot1_1][bot1_2] < 20) { // �˸�~����
        if (percent < 60) { // ���� : 60%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 60 && percent < 75) { // ���� : 15%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 75 && percent < 95) { // �� : 20%
            strcpy(bot_decide, Call);
        }
        else if (percent >= 95 && percent < 99) { // ���� : 4%
            strcpy(bot_decide, Die);
        }
        else { // ���� : 1%
            strcpy(bot_decide, All_in);
        }
    }
    else if (card[bot1_1][bot1_2] > 19 && card[bot1_1][bot1_2] <29) { // 8��~����
        if (percent < 45) { // ���� : 45%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 45 && percent < 55) { // ���� : 10%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 55 && percent < 79) { // �� : 24%
            strcpy(bot_decide, Call);
        }
        else if (percent >= 79 && percent < 99) { // ���� : 20%
            strcpy(bot_decide, Die);
        }
        else { // ���� : 1%
            strcpy(bot_decide, All_in);
        }
    }
    else if (card[bot1_1][bot1_2] == 30) { // ������
        if (percent < 50) { // ���� : 50%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 50 && percent < 70) { // ���� : 20%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 70 && percent < 90) { // �� : 20%
            strcpy(bot_decide, Call);
        }
        else if (percent >= 90 && percent < 99) { // ���� : 9%
            strcpy(bot_decide, Die);
        }
        else { // ���� : 1%
            strcpy(bot_decide, All_in);
        }
    }
    else if (card[bot1_1][bot1_2] == 33) { // ������
        if (percent < 30) { // ���� : 30%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 30 && percent < 60) { // ���� : 30%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 60 && percent < 85) { // �� : 25%
            strcpy(bot_decide, Call);
        }
        else if (percent >= 85 && percent < 99) { // ���� : 14%
            strcpy(bot_decide, Die);
        }
        else { // ���� : 1%
            strcpy(bot_decide, All_in);
        }
    }
    else { // ����, ���ֱ��� ����
        if (percent < 60) { // ���� : 60%
            strcpy(bot_decide, Half);
        }
        else if (percent >= 60 && percent < 75) { // ���� : 15%
            strcpy(bot_decide, Ddadang);
        }
        else if (percent >= 75 && percent < 98) { // �� : 23%
            strcpy(bot_decide, Call);
        }
        else if (percent <= 98 && percent < 99) { // ���� : 1%
            strcpy(bot_decide, Die);
        }
        else { // ���� : 1%
            strcpy(bot_decide, All_in);
        }
    }
}

void bot_betting() {
    if (card[bot1_1][bot1_2] == 1) { // ���ȱ���
        if (percent < 90) { // ���� : 90%
            bot_half();
        }
        else if (percent >= 90 && percent < 98) { // ���� : 8%
            bot_ddadang();
        }
        else if (percent >= 98 && percent < 99) { // �� : 1%
            bot_call();
        }
        else { // ���� : 1%
            bot_all_in();
        }
    }
    else if (card[bot1_1][bot1_2] == 2) { // ����
        if (percent < 80) { // ���� : 80%
            bot_half();
        }
        else if (percent >= 80 && percent < 95) { // ���� : 15%
            bot_ddadang();
        }
        else if (percent >= 95 && percent < 98) { // �� : 3%
            bot_call();
        }
        else if (percent >= 98 && percent < 99) { // ���� : 1%
            bot_die();
        }
        else { // ���� : 1%
            bot_all_in();
        }
    }
    else if (card[bot1_1][bot1_2] > 2 && card[bot1_1][bot1_2] < 8) { // 10��~6��
        if (percent < 75) { // ���� : 75%
            bot_half();
        }
        else if (percent >= 75 && percent < 90) { // ���� : 15%
            bot_ddadang();
        }
        else if (percent >= 90 && percent < 97) { // �� : 7%
            bot_call();
        }
        else if (percent >= 97 && percent < 99) { // ���� : 2%
            bot_die();
        }
        else { // ���� : 1%
            bot_all_in();
        }
    }
    else if (card[bot1_1][bot1_2] > 7 && card[bot1_1][bot1_2] < 13) { // 5��~1��
        if (percent < 70) { // ���� : 70%
            bot_half();
        }
        else if (percent >= 70 && percent < 90) { // ���� : 20%
            bot_ddadang();
        }
        else if (percent >= 90 && percent < 97) { // �� : 7%
            bot_call();
        }
        else if (percent >= 97 && percent < 99) { // ���� : 2%
            bot_die();
        }
        else { // ���� : 1%
            bot_all_in();
        }
    }
    else if (card[bot1_1][bot1_2] > 12 && card[bot1_1][bot1_2] < 20) { // �˸�~����
        if (percent < 60) { // ���� : 60%
            bot_half();
        }
        else if (percent >= 60 && percent < 75) { // ���� : 15%
            bot_ddadang();
        }
        else if (percent >= 75 && percent < 95) { // �� : 20%
            bot_call();
        }
        else if (percent >= 95 && percent < 99) { // ���� : 4%
            bot_die();
        }
        else { // ���� : 1%
            bot_all_in();
        }
    }
    else if (card[bot1_1][bot1_2] > 19 && card[bot1_1][bot1_2] <29) { // 8��~����
        if (percent < 45) { // ���� : 45%
            bot_half();
        }
        else if (percent >= 45 && percent < 55) { // ���� : 10%
            bot_ddadang();
        }
        else if (percent >= 55 && percent < 79) { // �� : 24%
            bot_call();
        }
        else if (percent >= 79 && percent < 99) { // ���� : 20%
            bot_die();
        }
        else { // ���� : 1%
            bot_all_in();
        }
    }
    else if (card[bot1_1][bot1_2] == 30) { // ������
        if (percent < 50) { // ���� : 50%
            bot_half();
        }
        else if (percent >= 50 && percent < 70) { // ���� : 20%
            bot_ddadang();
        }
        else if (percent >= 70 && percent < 90) { // �� : 20%
            bot_call();
        }
        else if (percent >= 90 && percent < 99) { // ���� : 9%
            bot_die();
        }
        else { // ���� : 1%
            bot_all_in();
        }
    }
    else if (card[bot1_1][bot1_2] == 33) { // ������
        if (percent < 30) { // ���� : 30%
            bot_half();
        }
        else if (percent >= 30 && percent < 60) { // ���� : 30%
            bot_ddadang();
        }
        else if (percent >= 60 && percent < 85) { // �� : 25%
            bot_call();
        }
        else if (percent >= 85 && percent < 99) { // ���� : 14%
            bot_die();
        }
        else { // ���� : 1%
            bot_all_in();
        }
    }
    else { // ����, ���ֱ��� ����
        if (percent < 60) { // ���� : 60%
            bot_half();
        }
        else if (percent >= 60 && percent < 75) { // ���� : 15%
            bot_ddadang();
        }
        else if (percent >= 75 && percent < 98) { // �� : 23%
            bot_call();
        }
        else if (percent >= 98 && percent < 99) { // ���� : 1%
            bot_die();
        }
        else { // ���� : 1%
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
        printf("�߸� �Է��Ͽ����ϴ�. \n");
        player_betting_input();
        player_betting();
    }
}

void card_open() {
    printf("����� �д� %s�Դϴ�. \n", pl_res);
    help();
}

void betting() {
    while(1) {
        //player
        if (cnt == 1) {
            printf("\n����� ���Դϴ�. \n\n");
            printf("\n���� �� : %d��\n��� ���� �� : %d��\n\n\n\n", pl_money, bot_money);
            while(1) {
                printf("�� �� �ִ� �ൿ�� ������ �����ϴ�.\n\n");
                printf("- ����\n- ��\n- üũ\n- ����\n\n");
                player_betting_input();
                if (!strcmp(pl_decide, Half) || !strcmp(pl_decide, Bbing) || !strcmp(pl_decide, Check) || !strcmp(pl_decide, Die)) {
                    break;
                }
                else {
                    printf("\n�߸� �Է��Ͽ����ϴ�. \n");
                }
            }
            player_betting();
            if (!strcmp(pl_decide, Check)) {
                printf("\n������ �ݾ� : 0��\n");
                printf("�ǵ� : %d��\n\n\n\n\n\n\n\n\n\n", betting_sum);
            }
            else {
                printf("\n������ �ݾ� : %d��\n", betting_money);
                printf("�ǵ� : %d��\n\n\n\n\n\n\n\n\n\n", betting_sum);
            }
            cnt++;
        }
        else if (!strcmp(bot_decide, All_in)) {
            printf("\n����� ���Դϴ�. \n\n\n");
            printf("\n���� �� : %d��\n��� ���� �� : %d��\n\n\n\n\n", pl_money, bot_money);
            while(1) {
                printf("�� �� �ִ� �ൿ�� ������ �����ϴ�.\n\n");
                printf("- ��\n- ����\n\n");
                player_betting_input();
                if (!strcmp(pl_decide, Call) || !strcmp(pl_decide, Die)) {
                    break;
                }
                else {
                    printf("\n�߸� �Է��Ͽ����ϴ�. \n");
                }
            }
            player_betting();
            printf("\n������ �ݾ� : %d��\n", betting_money);
            printf("�ǵ� : %d��\n\n\n\n\n\n\n\n\n\n", betting_sum);
        }
        else if (!strcmp(bot_decide, Call)) {
            printf("\n����� ���Դϴ�. \n\n\n");
            printf("\n���� �� : %d��\n��� ���� �� : %d��\n\n\n\n\n", pl_money, bot_money);
            while(1) {
                printf("�� �� �ִ� �ൿ�� ������ �����ϴ�.\n\n");
                printf("- ����\n- ��\n- ����\n\n");
                player_betting_input();
                if(!strcmp(pl_decide, Half) || !strcmp(pl_decide, Call) || !strcmp(pl_decide, Die)) {
                    break;
                }
                else {
                    printf("\n�߸� �Է��Ͽ����ϴ�. \n");
                }
            }
            player_betting();
            printf("\n������ �ݾ� : %d��\n", betting_money);
            printf("�ǵ� : %d��\n\n\n\n\n\n\n\n\n\n", betting_sum);
        }
        else {
            printf("\n����� ���Դϴ�. \n\n\n");
            printf("\n���� �� : %d��\n��� ���� �� : %d��\n\n\n\n\n", pl_money, bot_money);
            while(1) {
                printf("�� �� �ִ� �ൿ�� ������ �����ϴ�.\n\n");
                printf("- ����\n- ����\n- ����\n- ��\n- ����\n\n");
                player_betting_input();
                if(!strcmp(pl_decide, All_in) || !strcmp(pl_decide, Half) || !strcmp(pl_decide, Ddadang) || !strcmp(pl_decide, Call) || !strcmp(pl_decide, Die)) {
                    break;
                }
                else {
                    printf("\n�߸� �Է��Ͽ����ϴ�. \n");
                }
            }
            player_betting();
            printf("\n������ �ݾ� : %d��\n", betting_money);
            printf("�ǵ� : %d��\n\n\n\n\n\n\n\n\n\n", betting_sum);
        }

        //���� �� �ִ� ���
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
            printf("\n��밡 ������ �ݾ� : %d��\n", betting_money);
            printf("�ǵ� : %d��\n\n\n\n\n\n\n\n\n\n", betting_sum);
        }
        else if (!strcmp(pl_decide, Call)) {
            while (1) {
                bot_betting_input();
                if(!strcmp(bot_decide, Half) || !strcmp(bot_decide, Call) || !strcmp(bot_decide, Die)) {
                    break;
                }
            }
            bot_betting();
            printf("\n��밡 ������ �ݾ� : %d��\n", betting_money);
            printf("�ǵ� : %d��\n\n\n\n\n\n\n\n\n\n", betting_sum);
        }
        else {
            while(1) {
                bot_betting_input();
                if (!strcmp(bot_decide, All_in) || !strcmp(bot_decide, Half) || !strcmp(bot_decide, Ddadang) || !strcmp(bot_decide, Call) || !strcmp(bot_decide, Die)) {
                    break;
                }
            }
            bot_betting();
            printf("\n��밡 ������ �ݾ� : %d��\n", betting_money);
            printf("�ǵ� : %d��\n\n\n\n\n\n\n\n\n\n", betting_sum);
        }

        //���� �� �ִ� ���
        if (!strcmp(bot_decide, Die) || !strcmp(pl_decide, All_in) || !strcmp(pl_decide, Call)) break;
    }
}

void card_judge() {
	//���ȱ���
	if (card[pl1][pl2] == 1)
        res = 225;
	else if (card[bot1_1][bot1_2] == 1) res = 606;

	//������
	else if (card[pl1][pl2] == 33 && card[bot1_1][bot1_2] == 2)
		res = 225;
	else if (card[pl1][pl2] == 33 && card[bot1_1][bot1_2] != 2)
		card[pl1][pl2] = 27;
	else if (card[bot1_1][bot1_2] == 33 && card[pl1][pl2] == 2)
		res = 606;
	else if (card[bot1_1][bot1_2] == 33 && card[pl1][pl2] != 2)
		card[pl1][pl2] = 27;

	//������
	else if (card[pl1][pl2] == 30 && (3 < card[bot1_1][bot1_2] < 13))
		res == 225;
	else if (card[pl1][pl2] == 30 && !(3 < card[bot1_1][bot1_2] < 13))
		card[pl1][pl2] = 28;
	else if ((card[bot1_1][bot1_2] == 30 && (3 < card[pl1][pl2] < 13)))
		res == 606;
	else if (card[bot1_1][bot1_2] == 30 && (card[pl1][pl2] != 4 || card[pl1][pl2] != 5 || card[pl1][pl2] != 6 || card[pl1][pl2] != 7 || card[pl1][pl2] != 8 || card[pl1][pl2] != 9 || card[pl1][pl2] != 10 || card[pl1][pl2] != 11 || card[pl1][pl2] != 12))
		card[bot1_1][bot1_2] = 28;

	//���ֱ��� ����
	else if (card[pl1][pl2] == 32 && card[bot1_1][bot1_2] > 2)
		res = 202;
	else if (card[pl1][pl2] == 32 && card[bot1_1][bot1_2] <= 2) {}
	else if (card[bot1_1][bot1_2] == 32 && card[pl1][pl2] > 2)
		res = 202;
	else if (card[bot1_1][bot1_2] == 32 && card[pl1][pl2] <= 2) {}

	//����
	else if (card[pl1][pl2] == 31 && card[bot1_1][bot1_2] > 12)
		res = 202;
	else if (card[pl1][pl2] == 31 && card[bot1_1][bot1_2] <= 12) {}
	else if (card[bot1_1][bot1_2] == 31 && card[pl1][pl2] > 12)
		res = 202;
	else if (card[bot1_1][bot1_2] == 31 && card[pl1][pl2] <= 12) {}

	//������
	if (card[pl1][pl2] < card[bot1_1][bot1_2])
		res = 225;
	else if (card[bot1_1][bot1_2] < card[pl1][pl2])
		res = 606;
    else if (card[pl1][pl2] == card[bot1_1][bot1_2])
        res = 913;
}

void result() {
    if (res == 225) {
        printf("���� �� : %s, ��� �� : %s\n\n", pl_res, bot_res);
        printf("�¸� \n");
        help();
        pl_money += betting_sum;
        printf("\n���� �� : %d��\n��� ���� �� : %d��\n\n\n\n\n", pl_money, bot_money);
        cnt = 1;
        betting_money = 30000;
        betting_sum = 60000;
        pl_money -= 30000;
        bot_money -= 30000;
        strcpy(pl_decide, Blank);
        strcpy(bot_decide, Blank);
    }
    else if (res == 606) {
        printf("���� �� : %s, ��� �� : %s\n\n", pl_res, bot_res);
        printf("�й� \n");
        help();
        bot_money += betting_sum;
        printf("\n���� �� : %d��\n��� ���� �� : %d��\n\n\n\n\n", pl_money, bot_money);
        cnt = 1;
        betting_money = 30000;
        betting_sum = 60000;
        pl_money -= 30000;
        bot_money -= 30000;
        strcpy(pl_decide, Blank);
        strcpy(bot_decide, Blank);
    }
    else if (res == 202) {
        printf("���� �� : %s, ��� �� : %s\n\n", pl_res, bot_res);
        printf("���� (%s : %s)\n", !strcmp(pl_res, gusa) || !strcmp(pl_res, stupid_gusa)? "��": "���", !strcmp(pl_res, gusa) || !strcmp(bot_res, gusa)? "����": "���ֱ�������");
        printf("�ǵ��� �״�� �����˴ϴ�. \n");
        printf("\n\n���� �� : %d��\n��� ���� �� : %d��\n\n\n\n\n", pl_money, bot_money);
        cnt = 1;
        betting_money = 30000;
        strcpy(pl_decide, Blank);
        strcpy(bot_decide, Blank);
    }
    else if (res == 913) {
        printf("���� �� : %s, ��� �� : %s\n\n", pl_res, bot_res);
        printf("����\n");
        printf("�ǵ��� �״�� �����˴ϴ�. \n");
        printf("\n\n���� �� : %d��\n��� ���� �� : %d��\n\n\n\n\n", pl_money, bot_money);
        cnt = 1;
        betting_money = 30000;
        strcpy(pl_decide, Blank);
        strcpy(bot_decide, Blank);
    }
    else {
        printf("�̰� ������ ���Ѱǵ�");
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
        printf("\n\n\n\n\n\n���� �й�\n\n\n\n\n\n");
        printf("");
    }
    else if (bot_money <= 0) {
        printf("\n\n\n\n\n\n���� �¸�\n\n\n\n\n\n");
        printf("");
    }
    else {
        printf("�� �̰� ������ ���Ѱǵ�");
    }




    return 0;
}
