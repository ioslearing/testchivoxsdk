//
//  StartEngineClass.h
//  ChivoxEngine
//
//  Created by John on 16/9/14.
//  Copyright © 2016年 Chivox. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface StartEngineClass : NSObject

/**
 直接传入json参数
 */
@property (nonatomic,copy)NSString *jsonStartParams;

/**
 自定义音频保存名字
 */
@property (nonatomic,copy)NSString *audioName;
/**
 *  传入的是否是汉字 默认NO  
 */
@property (nonatomic,assign) BOOL isCnWord;

/**
 *  离线OR在线   native 或者  cloud
 */
@property (nonatomic,copy) NSString *coreProvideType;

//part3 audio
/**
 *  必须，录音机只录音wav格式音频，所以只能写wav。
 */
@property (nonatomic,copy) NSString *audioType;

/**
 * 录音时长，到此值会自动停止，单位ms
 */
@property (nonatomic,assign) NSInteger recDuration;
/**
 *  必须，目前只支持单声道,只能填1
 */
@property (nonatomic,assign)  int channel;
/**
 *  必须，每采样字节数, 支持：1 (单字节，8位) 和 2 (双字节，16位)
 */
@property (nonatomic,assign)  int sampleBytes;
/**
 *  必须, 采样率, 必须与音频本身采样率一致，不同语音服务有不同的要求, 例如语音评测要求16k
 */
@property (nonatomic,assign)  int sampleRate;

/**
 可选, 默认8，取值范围1～10. 若不在取值范围之内，则默认配置8.网络差的情况介意设置为3.
 */
@property (nonatomic,assign)  int quality;

/**
 可选，默认2
 */
@property (nonatomic,assign)  int complexity;

/**
 vbr配置，默认值0,若设置为1，则quality值作为vbr quality配置
 */
@property (nonatomic,assign)  int vbr;

/**
 *  音频压缩配置,speex:speex压缩(默认配置), raw:不压缩
 */
@property (nonatomic,copy) NSString *compress;
/**
 *  可选，默认0，即不返回volume值，该值通过回调engineStartCallBackWithAllResult返回
 */
@property (nonatomic,assign) int soundIntensityEnable;
/**
 *  可选，默认0，即关闭vad功能, vad结果通过回调返回
 */
@property (nonatomic,assign)  int vadEnable;
/**
 *  可选，默认0(不启用此功能)，设置音频vad参考时长(单位:s)，在该时间内vad不会返回音频结束
 */
@property (nonatomic,assign)  int vadRefDuration;

/**
 可选，默认0（开启设置为1支持自然拼读法是通过为单词指定音标的方法实现的，单词支持传入假词评测）
 */
@property (nonatomic,assign) int textMode;

/**
  wordlist 传参对象 eg:[{"word":"past", "pron":["p", "aa", "s", "t"]}]
 */
@property(nonatomic,copy) NSArray *refWordList;

/**
 当textMode打开时传入的假词 eg:[{"word":"past", "pron":["p", "aa", "s", "t"]}]
 */
@property(nonatomic,copy) NSArray *wordList;
/**
 当textMode=3时传入的文本 eg: {"text":"specia(p:1)", "prons":[[[“s”,”b”,”eh”,”sh”,”ax”],[“s”,”b”,”eh”,”sh”,”ax”,”sil”]]]}
 */
@property(nonatomic,copy) NSDictionary *textProns;
//part4 Request

//英文单词Request

/**
 *  必须，请求的内核类型
 */
@property (nonatomic,copy) NSString * coreType;
/**
 *  必须，参考文本
 */
@property (nonatomic,copy) NSString * refText;
/**
 *  可选，分制，默认100，4分和5分制需要配合相关资源使用
 */
@property (nonatomic,assign) int rank;

/**
 *  可选，选择服务器上的不同资源
 */
@property (nonatomic,copy) NSString * res;
/**
 * ensentrecscore的关键字keyword参数。
 */
@property (nonatomic,copy) NSString *keywords;

/**
 *  使用云服务时可选，指定服务器使返回结果附带音频下载地址
 */
@property (nonatomic,assign) int attachAudioUrl;
/**
 *  可选，仅eval模块生效，取值范围[-10~10], 松弛因子功能默认0关闭
 */
@property (nonatomic,assign) int relaxation_factor;
/**
 *  可选
 */
@property (nonatomic,assign) int robust;

//英文句子Request 在单词的基础上
@property (nonatomic,assign) int raw;
@property (nonatomic,assign) int sym;
@property (nonatomic,assign) int use_contispeech;
@property (nonatomic,assign) int use_only_conti;
@property (nonatomic,assign) int connti;
@property (nonatomic,assign) int tonematch;
@property (nonatomic,copy) NSArray * conn;
@property (nonatomic,copy) NSArray * noconn;

//英文段落Request
 
@property (nonatomic,copy) NSString *  qid;
@property (nonatomic,copy) NSString *lm;
//英文短文回答问题Request参数 pqan

@property (nonatomic,assign)int use_details;
/**
 朗读短文原始文本
 */
@property (nonatomic,copy) NSString *pqan_para;

/**
 要求考生回答的问题
 */
@property (nonatomic,copy) NSString *pqan_question;

/**
 参考答案文本, answer取2表示由命题老师给出的标准答案, answer取1表示请教学一线老师独立撰写的正确答案。每道考题要求标准答案2-5个左右，老师独立撰写的标准答案在15-20个左右。eg: pqan_lm: [ {answer: 2,text: "Every Sunday afternoon my friend takes Tom for a long walk in the park." }, {answer: 2, text: "Have a long walk in the park."}, {answer: 1,text: "Walk in the park."} ...]
 */
@property (nonatomic,copy) NSArray *pqan_lm;
//段落跟读Request en.pflw.exam

/**
 必需, 朗读文本
 */
@property (nonatomic,copy) NSString * pflw_lm;

//英文复述Reuqest  en.prtl.exam

/**
 参考答案文本, answer取2表示由命题老师给出的标准答案, answer取1表示请教学一线老师独立撰写的正确答案。answer取0表示考生答案, 不要求完全正确。每道考题要求标准答案2-5个左右, 老师独立撰写的标准答案在15-20个左右。eg: lm: [
 {answer: 2, text: "As we all know, different countries have their own special body language. If you don't know the differences, maybe you will misunderstand them. Jack is a good case in point. One day, he was travelling on a train to a small town in India. Next to him was a young man, who was a native. Jack was a talkative person and soon they became familiar to each other. \"Are you from India?\" asked Jack, the young man smiled and shook his head. So where are you from? Jack asked again. To Jack's surprise, the young man said that he was indeed a native. But why did you shake your head? Jack was a little confused. Luckily, the young man was very smart, he suddenly became aware that Jack must misunderstand him because he knew a little body language in different countries when expressing agree or disagree. After explaining to Jack, Jack's confusion had been melted. With time going on, Jack wanted to go to the restroom, he asked the young man, \"Is it the right way to the restroom\", and the young man nodded his head this time. \"Oh, I understand, it is on the opposite side.\""},
 {answer: 1, text: "As we all know, different countries have different body language, if you don't know it, you will misunderstand them. Jack is a case in point, one day he was on the train to a small town of India and next to him is an India young man. Jack is a talkative person, so they get familiar with each other quickly. Jack asked the young man whether he is from Indian, then the young man shook his head. So where are you from? Jack asked him, the young man said he was indeed a native, jack was confused about it, you are a native, but why you shook your head. Fortunately, the young man is a very smart and he knew something about body language he thought Jack was misunderstood his meaning, he explained it to Jack, and at last Jack made clear of it. With time going on, Jack went to a restaurant, he asked the waiter: is this the right way to the rest room? The waiter nodded his head, and then Jack knew that the opposite way is the right way of it."},
 {answer: 0, text: "Know the different countries. One day jack was plo on the tree. One suad tow in Indian, big million to each other. The group man smiled. He was indid was tale. Luckily the young man was smart. Because of the new, jack wanted to go to the rostile."}
 ... ]
 */
@property (nonatomic,copy) NSArray * prtl_lm;
//英文交际应用Request en.strn.exam

/**
 参考答案文本 eg:strn_lm: [
 {"answer":1.0, "text": "We should help do some house work."},
 ...
 ]
 */
@property (nonatomic,copy) NSArray * strn_lm;
//英文考试句子复述Request

/**
 朗读文本
 */
@property (nonatomic,copy) NSString * strl_lm;

//英文考试句子朗读Request

/**
 朗读文本
 */
@property (nonatomic,copy) NSString * sred_lm;

//英文看图说话评测 Request en.pict.exam

/**
 参考答案文本，answer取2表示由命题老师给出的标准答案，answer取1表示请教学一线老师独立撰写的正确答案。每道考题要求标准答案2-5个左右，老师独立撰写的标准答案在15-20个左右。eg:pict_lm:  [
 {answer: 2, text: "Lucy and Kate are neighbors. They have a good relationship. They often get together to kill time and help each other to do the homework. They do the sports together. They often go out together the walk the babies. Sometimes when the weather is bad, they will visit each other and enjoy a cup of tea in each other's home. At this time, their babies will stay together and have a good time, too."},
 {answer: 1, text: "Lucy and Kate are neighbors. The two families get along well with each other. Women often stay together for afternoon tea. Their children are best friends and they often take part in the sports game together. "},
 ...
 ]
 */
@property (nonatomic,copy) NSArray * pict_lm;

//英文口头作文评测 Request en.oesy.exam

/**
 // 参考答案文本，answer取2表示由命题老师给出的标准答案，answer取1表示请教学一线老师独立撰写的正确答案。answer取0表示考生答案, 不要求完全正确。每道考题要求标准答案2-5个左右，老师独立撰写的标准答案在15-20个左右.eg:oesy_lm: [
 {answer: 1, text: "I'm in a great class. There are thirty boys and twenty eight girls. All of us get on well with each other. We can also help each other often. All the students in my class are hard working. I believe each student in my class will have a bright future."},
 {answer: 0, text: "There are thirty boys and twenty eight girls in my class. We get along well with everyday and we can help with each other. We are very hard working."}
 ...
 ]
 */
@property (nonatomic,copy) NSArray * oesy_lm;
//英文情景对话评测 Request en.scne.exam
/**
 小写，表示考生在当前小题扮演的角色
 */
@property (nonatomic,copy)NSString *scne_role;
/**
 scne_lm字段内容比较多，总体而言，lm字段中用于存放该大题的所有对话内容，且同一小题中可以放置多种说法。具体在lm域下的各字段含义如下:
 //      text: 表示对话文本，可以有多种可能的答案和说法。
 //      active: 表示是否是当前小题的内容，active=1表示该文本是当前小题的可能对话文本；active=0表示该文本是非当前小题的对话文本，而是其他小题文本。
 //      role: 表示当前文本是角色role所说的文本。如果该role与当前小题要求考生扮演的角色一致表示考生该说的可能的答案；否则表示考题中给出的机器对话文本。
 //      answer: 表示答案文本的级别，answer=2表示试卷命题推荐的标准答案；answer=1表示一般老师撰写的正确答案；answer=0表示有争议的答案文本，或者考生易犯的错误文本。对于机器脚色，不设该项字段。
 //
 // 值得注意是:
 //      (1) 不仅要求包含当前小题的对话文本，而且需要包括其他所有小题的对话文本，因为当前小题的可能对话内容与上下文题相关。
 //      (2) 要注明角色
 //      (3) 要注明答案的准确性级别，且答案要保证有一定的丰富性，一般要求10种以上的可能答案。
 //      (4) 要注明是否是当前对应文本。
 eg: scne_lm: [
 {text: "Good morning. My name is Linda Smith. Can you tell me where your school is.", active: "1", role: "a"},
 {text: "City Center.", answer: 1.0, active: "1", role: "b"},
 {text: "Our school is in the centre of city.", answer: 1.0, active: "1", role: "b"},
 {text: "In the central part.", answer: 1.0, active: "1", role: "b"},
 {text: "It is in the downtown.", answer: 1.0, active: "1", role: "b"},
 {text: "Yes, my school is in the center of the city.", answer: 1.0, active: "1", role: "b"},
 {text: "My school is in the centre of city.", answer: 1.0, active: "1", role: "b"},
 {text: "Thank you. How many grades are there in your school?", active: "0", role: "a"},
 ...
 ]
 */
@property (nonatomic,copy) NSArray * scne_lm;
//英文三问五答评测

/**
 考生角色
 */
@property (nonatomic,copy)NSString *q3a5_role;

/**
 q3a5_lm的内容包含active="0", active="1",以及role="a"和role="b"的所有数据, 注意数据内容有先后顺序, role必须是小写
 eg: lm: [{text: "sentence 1", answer: 1.0, active: "1", role: "a"},
 {text: "sentence 2", active: "1", role: "b"}]
 */
@property (nonatomic,copy) NSArray *q3a5_lm;

//英文有限分支情景识别 en.choc.exam

/**
 参考答案文本, answer=2的是正确答案
 eg:   choc_lm: [
 {answer=0, text="In an office."},
 {answer=2, text="In a store."},
 {answer=0, text="In the street."},
 ...
 ]
 */
@property (nonatomic,copy) NSArray *choc_lm;
/**
 *  exam必须，评分精度
 */
@property (nonatomic,assign) float precision;
/**
 *  可选，句子与单词评分是否启用4分制，1为启用，0为分制跟随rank，默认1
 */
@property (nonatomic,assign) int ext_subitem_rank4;
/**
 *  可选，是否启用单词详细得分，1为启用，0为不启用，默认0
 */
@property (nonatomic,assign) int ext_word_details	;
/**
 *  可选，是否启用音素得分，1为启用，0为不启用，默认0
 */
@property (nonatomic,assign) int ext_phn_details;
/**
 *  可选，是否启用实时返回句子得分，默认不启用，1为启用，0为不启用
 */
@property (nonatomic,assign) int ext_cur_snt;
/**
 *use_speed，类型 int，返回结果中是否包含绘制语速曲线的数据点，1:包含，0:不包含;
 */
@property (nonatomic,assign) int use_speed;
/**
 *use_wrd_list，类型 int，返回结果中是否包含单词列表，1:包含，0:不包含;
 */
@property (nonatomic,assign) int use_wrd_list;
/**
 * use_energy，类型 int，返回结果中是否包含绘制能量曲线的数据点，1:包含，0:不包含;
 */
@property (nonatomic,assign) int use_energy;
/**
 *use_dim_score，类型 int，返回结果中是否包含各维度得分(能量得分、标准得分、语速得分、语调得分)，1:包含，0:不包含;
 */
@property (nonatomic,assign) int use_dim_score;
/**
 *use_tone，类型 int，返回结果中是否包含绘制语调曲线的数据点，1:包含，0:不包含;
 */
@property (nonatomic,assign) int use_tone;
/**
 * type，类型 string，原音音频格式，支持 mp3 和 wav 格式;
 */
@property (nonatomic,copy)NSString *type;
/**
 * url，类型 string，原音音频地址;该音频地址需要公网能访问。
 */
@property (nonatomic,copy)NSString *url;
/**
 *  可选，是否启用音素得分，1为启用，0为不启用，默认0
 */
@property (nonatomic,assign)int phone;
/**
 *  可选，是否返回纠错内核和asr内核的中间结果，1为启用，0为不启用，默认0
 */
@property (nonatomic,assign) int ext_cur_wrd;
/**
 *针对中文段落的是，显示单词详情
 */
@property (nonatomic,assign)int word;
/**
 * 参数：oovscore
 */
@property (nonatomic,assign)int oovscore;
/**
 *参数:cor
 */
@property (nonatomic,assign)int cor;
/**
 * 关键字
 */
@property (nonatomic,strong)NSArray *examkeywords;
@end
