//  CHAbstractListCollection.h
//  CHDataStructures.framework

/************************
 A Cocoa DataStructuresFramework
 Copyright (C) 2002  Phillip Morelock in the United States
 http://www.phillipmorelock.com
 Other copyrights for this specific file as acknowledged herein.
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *******************************/

#import <Foundation/Foundation.h>
#import "CHLinkedList.h"

/**
 An abstract class which implements many common behaviors of list-based collections.
 This class has a single instance variable on which all the implemented methods act,
 and also conforms to several protocols:
 
 - NSCoding
 - NSCopying
 - NSMutableCopying
 - NSFastEnumeration
 
 This class also contains concrete implementations for the following methods:
 <pre><code>
 -(NSUInteger) count
 -(NSString*) description
 -(NSEnumerator*) objectEnumerator
 -(NSArray*) allObjects
 -(void) removeAllObjects
 
 -(BOOL) containsObject:
 -(BOOL) containsObjectIdenticalTo:
 -(NSUInteger) indexOfObject:
 -(NSUInteger) indexOfObjectIdenticalTo:
 -(id) objectAtIndex:
 </code></pre>
 */
@interface CHAbstractListCollection : NSObject
	<NSCoding, NSCopying, NSMutableCopying, NSFastEnumeration>
{
	/** The linked list used for storing the contents of the data collection. */
	id<CHLinkedList> list;
}

/**
 Create a new collection with the contents of the given list.
 */
- (id) initWithList:(id<CHLinkedList>)aList;

// These method declarations cause duplicate documentation, but avoid build warnings.

- (NSUInteger) count;
- (NSEnumerator*) objectEnumerator;
- (NSArray*) allObjects;
- (void) removeAllObjects;

- (BOOL) containsObject:(id)anObject;
- (BOOL) containsObjectIdenticalTo:(id)anObject;
- (NSUInteger) indexOfObject:(id)anObject;
- (NSUInteger) indexOfObjectIdenticalTo:(id)anObject;
- (id) objectAtIndex:(NSUInteger)index;

@end