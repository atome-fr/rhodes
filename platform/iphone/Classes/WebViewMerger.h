/*------------------------------------------------------------------------
* (The MIT License)
*
* Copyright (c) 2008-2011 Rhomobile, Inc.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
* http://rhomobile.com
* Steve Richey
*------------------------------------------------------------------------*/

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>


@protocol WebViewMerger <NSObject>


/*
 * Return the active NSURLRequest of this webview.
 * The methodology is a bit different between UIWebView and WKWebView.
 * Defining it here one way helps to ensure we'll implement it in the same way in our categories.
*/
@property (nonatomic, strong) NSURLRequest *request;

/*
 * Returns the active NSURL. Again, this is a bit different between the two web views.
*/
@property (nonatomic, strong) NSURL *URL;

/*
 * Assign a delegate view for this webview.
*/
- (void) setDelegateViews: (id) delegateView;

/*
 * Load an NSURLRequest in the active webview.
*/
- (void) loadRequest: (NSURLRequest *) request;

/*
 * Convenience method to load a request from a string.
*/
- (void) loadRequestFromString: (NSString *) urlNameAsString;

/*
 * Returns true if it is possible to go back, false otherwise.
*/
- (BOOL) canGoBack;

/*
 * UIWebView has stringByEvaluatingJavaScriptFromString, which is synchronous.
 * WKWebView has evaluateJavaScript, which is asynchronous.
 * Since it's far easier to implement the latter in UIWebView, we define it here and do that.
*/
- (void) evaluateJavaScript: (NSString *) javaScriptString completionHandler: (void (^)(id, NSError *)) completionHandler;



@end

