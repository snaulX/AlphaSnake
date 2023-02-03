#ifndef ENIGMAENGINE_TANGARA_H
#define ENIGMAENGINE_TANGARA_H

typedef void* tgPtr;
/// Offset for pointer
typedef unsigned int tgOPtr;
typedef const char* tgStr;
typedef void(*tgLoadFunc)(tgPtr heap);
typedef void(*tgFunc)(tgPtr stack);

#ifdef __cplusplus
extern "C" {
#endif
tgPtr tgCreateHeap();
tgPtr tgHeapGet(tgPtr heap, tgStr name);
void tgFreeHeap(tgPtr heap);

tgPtr tgCreateInterface(tgPtr heap, tgStr name);
tgOPtr tgInterfaceAddPtr(tgPtr iface);
tgOPtr tgInterfaceAddInt(tgPtr iface);
tgOPtr tgInterfaceAddStr(tgPtr iface);

tgPtr tgCreateType(tgPtr heap, tgStr name);
tgOPtr tgTypeAddInt(tgPtr type);
tgOPtr tgTypeAddPtr(tgPtr type);
tgOPtr tgTypeAddStr(tgPtr type);
tgOPtr tgTypeAddFunc(tgPtr type, tgFunc func);
tgFunc tgTypeGetFunc(tgPtr type, tgOPtr func_offset);
tgOPtr tgTypeBeginParent(tgPtr type, tgStr name);
tgOPtr tgTypeExposeParent(tgPtr type, tgStr name);
void tgEndType(tgPtr type);

tgPtr tgPtrGet(tgPtr ptr, tgOPtr offset);
tgPtr tgObjectGet(tgPtr obj, tgOPtr offset);
void tgObjectSet(tgPtr obj, tgOPtr offset, tgPtr value);

tgPtr tgCreateStack();
tgPtr tgStackPop(tgPtr stack);
void tgStackPush(tgPtr stack, tgPtr ptr);
tgPtr tgStackNewObj(tgPtr stack, tgPtr type, tgPtr data);
void tgFreeStack(tgPtr stack);
#ifdef __cplusplus
}
#endif

#endif //ENIGMAENGINE_TANGARA_H
