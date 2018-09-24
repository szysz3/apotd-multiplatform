#import <Foundation/Foundation.h>

@class APOTDConstants, APOTDConstantsCompanion, APOTDPictureOfTheDayRepository, APOTDDate, APOTDDeferred, APOTDEmptyContinuation, APOTDStdlibThrowable, APOTDEmptyContinuationCompanion, APOTDWrappedContinuation, APOTDWrappedContinuationCompanion, APOTDDataObject, APOTDErrorObject, APOTDAsyncDispatcher, APOTDContinuationDispatcher, APOTDStdlibAbstractCoroutineContextElement, APOTDStdlibWorker, APOTDMainQueueDispatcher, APOTDPictureOfTheDay, APOTDBasePresenter, APOTDMainPresenter, APOTDStdlibFuture, APOTDStdlibTransferMode, APOTDStdlibFutureState, APOTDStdlibEnum;

@protocol APOTDStdlibContinuation, APOTDStdlibComparable, APOTDStdlibCoroutineContext, APOTDStdlibSuspendFunction0, APOTDStdlibCoroutineContextElement, APOTDStdlibCoroutineContextKey, APOTDStdlibContinuationInterceptor, APOTDBaseView, APOTDMainView, APOTDStdlibSuspendFunction;

NS_ASSUME_NONNULL_BEGIN

@interface KotlinBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end;

@interface KotlinBase (KotlinBaseCopying) <NSCopying>
@end;

__attribute__((objc_runtime_name("KotlinMutableSet")))
@interface APOTDMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end;

__attribute__((objc_runtime_name("KotlinMutableDictionary")))
@interface APOTDMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end;

@interface NSError (NSErrorKotlinException)
@property (readonly) id _Nullable kotlinException;
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDConstants : KotlinBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDConstantsCompanion : KotlinBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (readonly) NSString *APOTD_ENDPOINT;
@property (readonly) NSString *API_KEY;
@end;

@interface APOTDPictureOfTheDayRepository : KotlinBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)getAPOTDDate:(APOTDDate *)date callback:(id<APOTDStdlibContinuation>)callback __attribute__((swift_name("getAPOTD(date:callback:)")));
@end;

@protocol APOTDStdlibComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end;

@interface APOTDDate : KotlinBase <APOTDStdlibComparable>
- (instancetype)initWithDayOfMonth:(int32_t)dayOfMonth monthOfYear:(int32_t)monthOfYear year:(int32_t)year __attribute__((swift_name("init(dayOfMonth:monthOfYear:year:)"))) __attribute__((objc_designated_initializer));
- (NSString *)toDateFormatString __attribute__((swift_name("toDateFormatString()")));
- (APOTDDate *)addDayDaysToAdd:(int32_t)daysToAdd __attribute__((swift_name("addDay(daysToAdd:)")));
- (int32_t)compareToOther:(APOTDDate *)other __attribute__((swift_name("compareTo(other:)")));
- (APOTDDate *)addDaysDaysToAdd:(int32_t)daysToAdd __attribute__((swift_name("addDays(daysToAdd:)")));
- (APOTDDate *)now __attribute__((swift_name("now()")));
@property (readonly) int32_t dayOfMonth;
@property (readonly) int32_t monthOfYear;
@property (readonly) int32_t year;
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDDeferred : KotlinBase
- (instancetype)initWithContext:(id<APOTDStdlibCoroutineContext>)context block:(id<APOTDStdlibSuspendFunction0>)block __attribute__((swift_name("init(context:block:)"))) __attribute__((objc_designated_initializer));
@end;

@protocol APOTDStdlibContinuation
@required
- (void)resumeValue:(id _Nullable)value __attribute__((swift_name("resume(value:)")));
- (void)resumeWithExceptionException:(APOTDStdlibThrowable *)exception __attribute__((swift_name("resumeWithException(exception:)")));
@property (readonly) id<APOTDStdlibCoroutineContext> context;
@end;

@interface APOTDEmptyContinuation : KotlinBase <APOTDStdlibContinuation>
- (instancetype)initWithContext:(id<APOTDStdlibCoroutineContext>)context __attribute__((swift_name("init(context:)"))) __attribute__((objc_designated_initializer));
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDEmptyContinuationCompanion : APOTDEmptyContinuation
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (instancetype)initWithContext:(id<APOTDStdlibCoroutineContext>)context __attribute__((swift_name("init(context:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end;

@interface APOTDWrappedContinuation : KotlinBase <APOTDStdlibContinuation>
- (instancetype)initWithContext:(id<APOTDStdlibCoroutineContext>)context continuation:(id<APOTDStdlibContinuation>)continuation __attribute__((swift_name("init(context:continuation:)"))) __attribute__((objc_designated_initializer));
@property (readonly) id<APOTDStdlibContinuation> continuation;
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDWrappedContinuationCompanion : APOTDWrappedContinuation
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
- (instancetype)initWithContext:(id<APOTDStdlibCoroutineContext>)context continuation:(id<APOTDStdlibContinuation>)continuation __attribute__((swift_name("init(context:continuation:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (void)resumeValue:(id)value __attribute__((swift_name("resume(value:)")));
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDDataObject : KotlinBase
- (instancetype)initWithValue:(id _Nullable)value continuation:(id<APOTDStdlibContinuation>)continuation __attribute__((swift_name("init(value:continuation:)"))) __attribute__((objc_designated_initializer));
@property (readonly) id _Nullable value;
@property (readonly) id<APOTDStdlibContinuation> continuation;
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDErrorObject : KotlinBase
- (instancetype)initWithException:(APOTDStdlibThrowable *)exception continuation:(id<APOTDStdlibContinuation>)continuation __attribute__((swift_name("init(exception:continuation:)"))) __attribute__((objc_designated_initializer));
@property (readonly) APOTDStdlibThrowable *exception;
@property (readonly) id<APOTDStdlibContinuation> continuation;
@end;

@protocol APOTDStdlibCoroutineContext
@required
- (id _Nullable)foldInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<APOTDStdlibCoroutineContextElement>))operation __attribute__((swift_name("fold(initial:operation:)")));
- (id<APOTDStdlibCoroutineContextElement> _Nullable)getKey:(id<APOTDStdlibCoroutineContextKey>)key __attribute__((swift_name("get(key:)")));
- (id<APOTDStdlibCoroutineContext>)minusKeyKey:(id<APOTDStdlibCoroutineContextKey>)key __attribute__((swift_name("minusKey(key:)")));
- (id<APOTDStdlibCoroutineContext>)plusContext:(id<APOTDStdlibCoroutineContext>)context __attribute__((swift_name("plus(context:)")));
@end;

@protocol APOTDStdlibCoroutineContextElement <APOTDStdlibCoroutineContext>
@required
@property (readonly) id<APOTDStdlibCoroutineContextKey> key;
@end;

@interface APOTDStdlibAbstractCoroutineContextElement : KotlinBase <APOTDStdlibCoroutineContextElement>
- (instancetype)initWithKey:(id<APOTDStdlibCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer));
@end;

@protocol APOTDStdlibContinuationInterceptor <APOTDStdlibCoroutineContextElement>
@required
- (id<APOTDStdlibContinuation>)interceptContinuationContinuation:(id<APOTDStdlibContinuation>)continuation __attribute__((swift_name("interceptContinuation(continuation:)")));
@end;

@interface APOTDContinuationDispatcher : APOTDStdlibAbstractCoroutineContextElement <APOTDStdlibContinuationInterceptor>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithKey:(id<APOTDStdlibCoroutineContextKey>)key __attribute__((swift_name("init(key:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (BOOL)dispatchResumeValue:(id _Nullable)value continuation:(id<APOTDStdlibContinuation>)continuation __attribute__((swift_name("dispatchResume(value:continuation:)")));
- (BOOL)dispatchResumeWithExceptionException:(APOTDStdlibThrowable *)exception continuation:(id<APOTDStdlibContinuation>)continuation __attribute__((swift_name("dispatchResumeWithException(exception:continuation:)")));
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDAsyncDispatcher : APOTDContinuationDispatcher
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (readonly) APOTDStdlibWorker *worker;
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDMainQueueDispatcher : APOTDContinuationDispatcher
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDPictureOfTheDay : KotlinBase
- (instancetype)initWithDate:(NSString *)date explanation:(NSString *)explanation media_type:(NSString *)media_type title:(NSString *)title url:(NSString *)url __attribute__((swift_name("init(date:explanation:media_type:title:url:)"))) __attribute__((objc_designated_initializer));
- (NSString *)component1 __attribute__((swift_name("component1()")));
- (NSString *)component2 __attribute__((swift_name("component2()")));
- (NSString *)component3 __attribute__((swift_name("component3()")));
- (NSString *)component4 __attribute__((swift_name("component4()")));
- (NSString *)component5 __attribute__((swift_name("component5()")));
- (APOTDPictureOfTheDay *)doCopyDate:(NSString *)date explanation:(NSString *)explanation media_type:(NSString *)media_type title:(NSString *)title url:(NSString *)url __attribute__((swift_name("doCopy(date:explanation:media_type:title:url:)")));
@property (readonly) NSString *date;
@property (readonly) NSString *explanation;
@property (readonly) NSString *media_type;
@property (readonly) NSString *title;
@property (readonly) NSString *url;
@end;

@interface APOTDBasePresenter : KotlinBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)attachView:(id<APOTDBaseView>)view __attribute__((swift_name("attach(view:)")));
- (void)detach __attribute__((swift_name("detach()")));
- (void)onViewAttached __attribute__((swift_name("onViewAttached()")));
- (void)onViewDetached __attribute__((swift_name("onViewDetached()")));
@property (readonly) id<APOTDBaseView> _Nullable view;
@end;

@protocol APOTDBaseView
@required
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDMainPresenter : APOTDBasePresenter
- (instancetype)initWithUiContext:(id<APOTDStdlibCoroutineContext>)uiContext repository:(APOTDPictureOfTheDayRepository *)repository __attribute__((swift_name("init(uiContext:repository:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (void)showNextAPOTD __attribute__((swift_name("showNextAPOTD()")));
- (void)showPreviousAPOTD __attribute__((swift_name("showPreviousAPOTD()")));
- (void)attachView:(id<APOTDMainView>)view __attribute__((swift_name("attach(view:)")));
@property (readonly) id<APOTDMainView> _Nullable view;
@end;

@protocol APOTDMainView <APOTDBaseView>
@required
- (void)showErrorErrorMessage:(NSString *)errorMessage __attribute__((swift_name("showError(errorMessage:)")));
- (void)showLoadingIsLoading:(BOOL)isLoading __attribute__((swift_name("showLoading(isLoading:)")));
- (void)showAPOTDApotd:(APOTDPictureOfTheDay *)apotd __attribute__((swift_name("showAPOTD(apotd:)")));
- (void)changeNextButtonStateIsEnabled:(BOOL)isEnabled __attribute__((swift_name("changeNextButtonState(isEnabled:)")));
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDUtils : KotlinBase
@property (class, readonly) APOTDDate *now;
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDUtilsCoroutines : KotlinBase
+ (APOTDDeferred *)asyncContext:(id<APOTDStdlibCoroutineContext>)context block:(id<APOTDStdlibSuspendFunction0>)block __attribute__((swift_name("async(context:block:)")));
+ (void)launchContext:(id<APOTDStdlibCoroutineContext>)context block:(id<APOTDStdlibSuspendFunction0>)block __attribute__((swift_name("launch(context:block:)")));
@end;

@protocol APOTDStdlibSuspendFunction
@required
@end;

@protocol APOTDStdlibSuspendFunction0 <APOTDStdlibSuspendFunction>
@required
@end;

@interface APOTDStdlibThrowable : KotlinBase
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(APOTDStdlibThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(APOTDStdlibThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
@property (readonly) APOTDStdlibThrowable * _Nullable cause;
@property (readonly) NSString * _Nullable message;
@end;

@protocol APOTDStdlibCoroutineContextKey
@required
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDStdlibWorker : KotlinBase
- (instancetype)initWithId:(int32_t)id __attribute__((swift_name("init(id:)"))) __attribute__((objc_designated_initializer));
- (APOTDStdlibFuture *)requestTerminationProcessScheduledJobs:(BOOL)processScheduledJobs __attribute__((swift_name("requestTermination(processScheduledJobs:)")));
- (APOTDStdlibFuture *)scheduleMode:(APOTDStdlibTransferMode *)mode producer:(id _Nullable (^)(void))producer job:(id _Nullable (^)(id _Nullable))job __attribute__((swift_name("schedule(mode:producer:job:)")));
@property (readonly) int32_t id;
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDStdlibFuture : KotlinBase
- (id _Nullable)consumeCode:(id _Nullable (^)(id _Nullable))code __attribute__((swift_name("consume(code:)")));
- (id _Nullable)result __attribute__((swift_name("result()")));
@property (readonly) int32_t id;
@property (readonly) APOTDStdlibFutureState *state;
@end;

@interface APOTDStdlibEnum : KotlinBase <APOTDStdlibComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
- (id)clone __attribute__((swift_name("clone()")));
- (int32_t)compareToOther:(APOTDStdlibEnum *)other __attribute__((swift_name("compareTo(other:)")));
@property (readonly) NSString *name;
@property (readonly) int32_t ordinal;
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDStdlibTransferMode : APOTDStdlibEnum
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
@property (class, readonly) APOTDStdlibTransferMode *checked;
@property (class, readonly) APOTDStdlibTransferMode *unchecked;
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (int32_t)compareToOther:(APOTDStdlibTransferMode *)other __attribute__((swift_name("compareTo(other:)")));
@property (readonly) int32_t value;
@end;

__attribute__((objc_subclassing_restricted))
@interface APOTDStdlibFutureState : APOTDStdlibEnum
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
@property (class, readonly) APOTDStdlibFutureState *invalid;
@property (class, readonly) APOTDStdlibFutureState *scheduled;
@property (class, readonly) APOTDStdlibFutureState *computed;
@property (class, readonly) APOTDStdlibFutureState *cancelled;
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (int32_t)compareToOther:(APOTDStdlibFutureState *)other __attribute__((swift_name("compareTo(other:)")));
@property (readonly) int32_t value;
@end;

NS_ASSUME_NONNULL_END
