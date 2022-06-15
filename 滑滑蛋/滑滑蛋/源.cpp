#include<iostream>
#include<string>

using namespace std;

enum country { China, computer, erciyuan, MgGuo, K_on, Moon };

struct Player
{
	int order;
	int num;
	string name;
	country country;
	int age;
	float goal;
}player[8] =
{
{ 0, 1, "嗯so胖", China, 18, 66.9},
{ 0, 2, "舞俊羊", China, 18, 66.8},
{ 0, 3, "乌龟盐", China, 18, 99.6},
{ 0, 4, "污菌养", China, 18, 77.7},
{ 0, 5, "鹀龜鴹", Moon, 999, 36.4},
{ 0, 6, "无君痒", erciyuan, 3, 66.6},
{ 0, 7, "wujunyang", MgGuo, 114514, 23.3},
{ 0, 8, "5-jun-young", computer, 1919810, 10.0}
};

//冒泡排序+成绩排名
void change(float *chengji)
{
	const int size = 8;
	for (int i = 1; i <= size - 1; i++)
	{
		for (int j = 0; j <= size - i -1; j++)
		{
			float midvalue = 0;
			if (chengji[j] >= chengji[j + 1])
			{
				midvalue = chengji[j];
				chengji[j] = chengji[j + 1];
				chengji[j + 1] = midvalue;
			}
		}
	}

	for (int i = 8; i >= 1; i--)
	{
		for (int j = 0; j <= 7; j++)
		{
			if (player[j].goal == chengji[i - 1])
			{
				player[j].order = i;
				cout << "获得第" << player[j].order << "名的是" << player[j].name << ",成绩为：" << player[j].goal << endl;
				break;
			}
		}
	}

}


string Imformation(int i) //参赛选手的介绍词。
{
	switch (i)
	{
	case 1:
		return "嗯童鞋虽然有着中英混搭的性质，其实是报名时一个小小的意外，据某位热心市民透露，嗯so胖为他掩埋自己背后的身份用来的化名，其真实目的尚未明晰。主办方认为应该严查身份，但却因重重阻力而收效甚微。总之，身为观众，谜样男子蜜汁身份，带来多少意外和惊喜呢？有关嗯so胖同学的更多神秘信息敬请订阅本电台新闻浏览节目，一个季度只要500元，首个季度更能享受高达5元优惠！";
	case 2:
		return "空之少年舞同学来自China的一个广袤的高原，澄空碧天之下生长的舞同学对滑蛋保持一番虔诚的信仰。“私以为，地面的生灵终须回归去高天之上，翩迁于云霞之间”他如此说过。信仰，使舞同学最终以最坚定的意志站在滑滑蛋的最后舞台上，高天原的少年，你将魂归何处？";
	case 3:
		return "海之少年乌同学来自China的一个古老的渔村，（温馨提示，受乌同学匿名请求的热心市民委托，请大家年他中间的字时念jun谢谢。）古老的传统无法阻止乌同学滑蛋的热情，最终，他冲破重重阻碍来到这里一展自身技艺。古老的滑蛋技巧与当下水乳交融，乌同学究竟会走到那一步呢？";
	case 4:
		return "陆之少年污同学来自China的一个幽深的山谷，高山深谷造就了污同学强韧的体魄，在那片绝地中，唯有滑蛋是人们艰苦一日的娱乐。恶劣的土地也许无法孕育出繁盛的文明，但却不能阻止顽强的山民找寻生活的意义。滑滑蛋，在山民之间流传已久的庆典娱乐，能让污同学的斗志燃烧到何时？";
	case 5:
		return "（导演，这仨字咋念...）久等了，接下来出场的选手是来自月亮的奇特名字同学，荒凉的月球突然诞生的生命降临此地，但他第一时间想到的竟然是参加滑滑蛋大赛！据某位匿名热心市民传说，月亮同学将在他滑滑蛋大赛获得冠军之时达到1000岁，届时将会有神秘文明自月球背面显现，想要一睹地外文明的观众不妨按下眼前的购买按钮支付1000元免费获得月背望远镜一副，沙瀑S，助理每个人天文梦。";
	case 6:
		return "无同学是个自称来自二次元的生物，但怎么看都是三次元的选手。虽然遗憾地从二次元的世界里离开，但遵循某位热心市民的提醒，无同学参与了本次滑滑蛋大赛，争取取得冠军就能重返二次元的世界。阴差阳错地，无同学得到了来自二次元的另一个自己的力量，这股神秘力量究竟是什么？详情请购买最新上市的无同学的新书《关于来自二次元的我被放逐到三次元还成为那里的冠军过上了幸福生活最后却被迫重返二次元的故事》第三卷，首发购买更可打八折哦！";
	case 7:
		return "wujunyang同学是一个来自镁锅的机器人，作为滑滑蛋型号的第114514型机器人，wujunyang采用了最新型的滑蛋运动装置，让他能在滑蛋的过程中保持恐怖的专注力，全程勇猛地冲刺。但是，作为一个实验机型，本机型在运行期间会间接释放令人感到不悦的气息，请环保人士尽量保持客观公正的态度对待本机。相关产品以及周边敬请关注镁锅公司官网。";
	case 8:
		return "5-jun-young，他是一代传奇。自从某位热心市民在世纪初第一次于地下发掘出装载有5-jun-young系统的机器时，滑滑蛋，这项起源于该机器内置系统的一段模糊不清的录像所展现出来的运动，一夜之间风靡全球，令无数人民疯狂。如今想来已经是第50年了，在这半世纪的过程中，5-jun-young呈现出恐怖的统治力，未有一人能将其击败，今年，能否有哪位勇士能成功终结传奇的故事呢？赶快为你们心中的勇士投下你最真挚的一票吧，每票只要15元。";
	}
}

int main()
{


	cout << "欢迎来到世界男子500m滑滑蛋大赛，下面有请参赛选手。本节目由吴氏非凡企业赞助播出，非凡之选，每一个针男人的选择。\n-------" << endl;


	//依次打印选手信息。
	for (int i = 0; i < 8; i++)
	{
		cout << "下面有请" << player[i].age << "岁的" << player[i].num << "号选手" << player[i].name << "童鞋：\n" << Imformation(player[i].num) << "\n-------\n";
	}

	cout << "经历了一番激烈的角逐......" << endl;

	//开始排序（冒泡）,并输出。
	float chengji[8] = { player[0].goal, player[1].goal, player[2].goal, player[3].goal, player[4].goal, player[5].goal, player[6].goal, player[7].goal };
	change(chengji);

	return 0;
}