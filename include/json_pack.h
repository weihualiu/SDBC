#ifndef JSON_PACK
#define JSON_PACK

#ifndef  __STRICT_ANSI__
#define __STRICT_ANSI__
#endif

#include <json.h>
/**********************************************************************************
 * ��һ�鹤�ߺ�������SDBC��JSON֮�������ת����
 * ԭ��SDBCģ���name�����Ǹ������ݣ��磺�ֶ����ơ���������������decode���ȵ�,
 * ��ʹ�ñ��麯����Ҫ��name������JSON���ָ�ʽ��
 *******************************************************************************/

typedef struct json_object *JSON_OBJECT;
#define struct_to_json(json,data,typ,choose) stu_to_json((json),(data),(typ),(choose),0)
/***********************************************************************
 * ���洢����Ĵ���׷������ ,�������100�ֽڣ��º����׷����������
 ***********************************************************************/

#define add_string_to_json(json,name,val) json_object_object_add((json),(name),json_object_new_string(val))


#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * C struct to json object by SDBC parttention
 * chooseΪNULL��ѡ��ȫ���ֶΡ�Ϊ"",ѡ��ȫ���ǿ��ֶ�
 * choose ������ѡ����ֶ������б�����,��|������
 * Ҳ�������ֶ�˳�ţ�˳�ŷ�Χ�������������б����ã��磺"0-5,8,11,zip,code"
 *******************************************************************************/

JSON_OBJECT stu_to_json(JSON_OBJECT json,void *data,T_PkgType * typ,const char *choose,char *colidx);

/*************************************************************************
 * json_object to sdbc string...
 *************************************************************************/

char * json_to_sdbc(char *tmp,JSON_OBJECT json);

/**********************************************************************************
 * json object to C struct by SDBC parrtention
 **********************************************************************************/

int json_to_struct(void *data,JSON_OBJECT json,T_PkgType *typ);

char * json_get_string(JSON_OBJECT from,const char *key);
int json_to_Str(char *buf,JSON_OBJECT json,T_PkgType *tp);

//T_PkgType --> JSON result:[]
int tpl_to_JSON(T_PkgType *tp,JSON_OBJECT result);
JSON_OBJECT jerr(int jerrno,const char *errmsg);
//ʧ�ܷ���NULL���ɹ�����Ӧ���������ͷ�
T_PkgType * new_tpl_fromJSON(JSON_OBJECT tpl_json);
// at tpl_lib.c
T_PkgType * mk_tpl(const char *tabname);
int tpl_to_lib(T_PkgType *tpl,const char *tabname);
void tpl_lib_cancel(void);

#ifdef __cplusplus
}
#endif

#endif