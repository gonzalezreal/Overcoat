// TwitterClient.h
//
// Copyright (c) 2014 Guillermo Gonzalez
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Overcoat/Overcoat.h>
#import "TimelineType.h"

@class ACAccount;
@class PMKPromise;

@interface TwitterClient : OVCHTTPSessionManager

@property (strong, nonatomic, readonly) ACAccount *account;

- (id)initWithAccount:(ACAccount *)account managedObjectContext:(NSManagedObjectContext *)context;

/**
 Fetches a collection of tweets, ordered with the most recent first.
 
 @param timeline The type of timeline.
 @param parameters - The parameters for the request.
 
 @return A `Promise` that will `then` an array of `Tweet` objects.
 */
- (PMKPromise *)fetchTimeline:(TimelineType)timelineType parameters:(NSDictionary *)parameters;

/**
 Fetches a cursored collection of user IDs for every user the specified user is following.
 
 @return A `Promise` that will `then` a `UserIdentifierCollection` object.
 */
- (PMKPromise *)fetchFriendIdentifiersWithCursor:(NSNumber *)cursor;

/**
 Fetches a cursored collection of user IDs for every user following the specified user.
 
 @return A `Promise` that will `then` a `UserIdentifierCollection` object.
 */
- (PMKPromise *)fetchFollowerIdentifiersWithCursor:(NSNumber *)cursor;

/**
 Fetches fully-hydrated user objects for up to 100 users per request.
 
 @return A `Promise` that will `then` an array of `TwitterUser` objects.
 */
- (PMKPromise *)lookupUsersWithIdentifiers:(NSArray *)identifiers;

@end
