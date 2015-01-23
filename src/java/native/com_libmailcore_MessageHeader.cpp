#include "com_libmailcore_MessageHeader.h"

#include "TypesUtils.h"
#include "JavaHandle.h"
#include "MCMessageHeader.h"
#include "MCDefines.h"

using namespace mailcore;

#define nativeType MessageHeader
#define javaType nativeType

MC_JAVA_SYNTHESIZE_STRING(setMessageID, messageID)

JNIEXPORT jboolean JNICALL Java_com_libmailcore_MessageHeader_isMessageIDAutoGenerated
  (JNIEnv * env, jobject obj)
{
    MC_POOL_BEGIN;
    jboolean result = (jboolean) MC_JAVA_NATIVE_INSTANCE->isMessageIDAutoGenerated();
    MC_POOL_END;
    return result;
}

MC_JAVA_SYNTHESIZE(Array, setReferences, references)
MC_JAVA_SYNTHESIZE(Array, setInReplyTo, inReplyTo)
    
JNIEXPORT jobject JNICALL Java_com_libmailcore_MessageHeader_date
  (JNIEnv * env, jobject obj)
{
    MC_POOL_BEGIN;
    jobject result = timeToJavaDate(env, MC_JAVA_NATIVE_INSTANCE->date());
    MC_POOL_END;
    return result;
}

JNIEXPORT void JNICALL Java_com_libmailcore_MessageHeader_setDate
  (JNIEnv * env, jobject obj, jobject date)
{
    MC_POOL_BEGIN;
    MC_JAVA_NATIVE_INSTANCE->setDate(javaDateToTime(env, date));
    MC_POOL_END;
}

JNIEXPORT jobject JNICALL Java_com_libmailcore_MessageHeader_receivedDate
  (JNIEnv * env, jobject obj)
{
    MC_POOL_BEGIN;
    jobject result = timeToJavaDate(env, MC_JAVA_NATIVE_INSTANCE->receivedDate());
    MC_POOL_END;
    return result;
}

JNIEXPORT void JNICALL Java_com_libmailcore_MessageHeader_setReceivedDate
  (JNIEnv * env, jobject obj, jobject date)
{
    MC_POOL_BEGIN;
    MC_JAVA_NATIVE_INSTANCE->setReceivedDate(javaDateToTime(env, date));
    MC_POOL_END;
}

MC_JAVA_SYNTHESIZE(Address, setSender, sender)
MC_JAVA_SYNTHESIZE(Address, setFrom, from)
MC_JAVA_SYNTHESIZE(Array, setTo, to)
MC_JAVA_SYNTHESIZE(Array, setCc, cc)
MC_JAVA_SYNTHESIZE(Array, setBcc, bcc)
MC_JAVA_SYNTHESIZE(Array, setReplyTo, replyTo)
MC_JAVA_SYNTHESIZE_STRING(setSubject, subject)
MC_JAVA_SYNTHESIZE_STRING(setUserAgent, userAgent)

JNIEXPORT void JNICALL Java_com_libmailcore_MessageHeader_setExtraHeader
  (JNIEnv * env, jobject obj, jstring name, jstring value)
{
    MC_POOL_BEGIN;
    MC_JAVA_NATIVE_INSTANCE->setExtraHeader(MC_FROM_JAVA(String, name), MC_FROM_JAVA(String, value));
    MC_POOL_END;
}

JNIEXPORT void JNICALL Java_com_libmailcore_MessageHeader_removeExtraHeader
  (JNIEnv * env, jobject obj, jstring name)
{
    MC_POOL_BEGIN;
    MC_JAVA_NATIVE_INSTANCE->removeExtraHeader(MC_FROM_JAVA(String, name));
    MC_POOL_END;
}

JNIEXPORT jstring JNICALL Java_com_libmailcore_MessageHeader_extraHeaderValueForName
  (JNIEnv * env, jobject obj, jstring name)
{
    MC_POOL_BEGIN;
    jobject result = MC_TO_JAVA(MC_JAVA_NATIVE_INSTANCE->extraHeaderValueForName(MC_FROM_JAVA(String, name)));
    MC_POOL_END;
    return (jstring) result;
}

JNIEXPORT jobject JNICALL Java_com_libmailcore_MessageHeader_allExtraHeadersNames
  (JNIEnv * env, jobject obj)
{
    MC_POOL_BEGIN;
    jobject result = MC_JAVA_BRIDGE_GET(allExtraHeadersNames);
    MC_POOL_END;
    return result;
}

JNIEXPORT jstring JNICALL Java_com_libmailcore_MessageHeader_extractedSubject
  (JNIEnv * env, jobject obj)
{
    MC_POOL_BEGIN;
    jstring result = MC_JAVA_BRIDGE_GET_STRING(extractedSubject);
    MC_POOL_END;
    return result;
}

JNIEXPORT jstring JNICALL Java_com_libmailcore_MessageHeader_partialExtractedSubject
  (JNIEnv * env, jobject obj)
{
    MC_POOL_BEGIN;
    jstring result = MC_JAVA_BRIDGE_GET_STRING(partialExtractedSubject);
    MC_POOL_END;
    return result;
}

JNIEXPORT void JNICALL Java_com_libmailcore_MessageHeader_importHeadersData
  (JNIEnv * env, jobject obj, jbyteArray data)
{
    MC_POOL_BEGIN;
    MC_JAVA_NATIVE_INSTANCE->importHeadersData(MC_FROM_JAVA(Data, data));
    MC_POOL_END;
}

JNIEXPORT jobject JNICALL Java_com_libmailcore_MessageHeader_replyHeader
  (JNIEnv * env, jobject obj, jboolean replyAll, jobject excludedRecipients)
{
    MC_POOL_BEGIN;
    jobject result = MC_TO_JAVA(MC_JAVA_NATIVE_INSTANCE->replyHeader(replyAll, MC_FROM_JAVA(Array, excludedRecipients)));
    MC_POOL_END;
    return result;
}

JNIEXPORT jobject JNICALL Java_com_libmailcore_MessageHeader_forwardHeader
  (JNIEnv * env, jobject obj)
{
    MC_POOL_BEGIN;
    jobject result = MC_JAVA_BRIDGE_GET(forwardHeader);
    MC_POOL_END;
    return result;
}

MC_JAVA_BRIDGE