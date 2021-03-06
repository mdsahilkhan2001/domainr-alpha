#import <UIKit/UIKit.h>
#import "CJSONDeserializer.h"

@class DomainrTableView;
@class Reachability;

@interface MainViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UISearchBarDelegate, UINavigationBarDelegate> {	
	IBOutlet DomainrTableView			*myTableView;
	IBOutlet UISearchBar				*mySearchBar;
	IBOutlet UIActivityIndicatorView	*activityIndicator;
	IBOutlet UIView						*whiteBgView;
	
	NSData					*jsonData;
	NSURL					*jsonURL;
	NSMutableData			*receivedData;
	NSString				*jsonString;
	NSURLConnection			*theConnection;
	
	NSString				*searchQuery;
	NSMutableArray			*results;
	NSMutableArray			*favouritesArray;
	NSMutableArray			*resultObjectsArray;
	BOOL					loading;
	
	NSDate					*previousTimeStamp;
	
	Reachability			*internetReach;
	
	BOOL					keyboardHidden;
	
	BOOL					firstLaunch;
	UIAlertView				*alert;
}

@property (nonatomic, retain) DomainrTableView	*myTableView;
@property (nonatomic, retain) UISearchBar		*mySearchBar;

- (void) toggleActivityIndicator:(BOOL)show;
- (void) setKeyboardState:(BOOL)show;
- (void)_showKeyboardWorkAround;

/* i know, these are hacky, got a better idea? ok fine, then fork it and fix it. jeez */ 
- (void)_showClearButton;
- (void)_hideClearButton;

- (void) search;
- (BOOL) networkAvailable;

@end
