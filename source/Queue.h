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

//  Queue.h
//  DataStructuresFramework

#import <Foundation/Foundation.h>

/**
 A <a href="http://en.wikipedia.org/wiki/Queue_(data_structure)">queue</a> protocol
 with methods for <a href="http://en.wikipedia.org/wiki/FIFO">FIFO</a> operations.
 */
@protocol Queue <NSObject>

/**
 Add an object to the back of the queue.
 
 @param anObject The object to add to the queue; must not be <code>nil</code>, or an
        <code>NSInvalidArgumentException</code> will be raised.
 */
- (void) enqueueObject:(id)anObject;

/**
 Remove and return the object at the front of the queue.
 
 @return The frontmost object in the queue, or <code>nil</code> if the queue is empty.
 */
- (id) dequeueObject;

/**
 Examine the object at the front of the queue without removing it.
 
 @return The frontmost object in the queue, or <code>nil</code> if the queue is empty.
 */
- (id) frontObject;

/**
 Returns the number of objects currently in the queue.
 
 @return The number of objects currently in the queue.
 */
- (NSUInteger) count;

/**
 Remove all objects from the queue; if it is already empty, there is no effect.
 */
- (void) removeAllObjects;

/**
 Returns an enumerator that accesses each object in the queue from front to back.
 
 NOTE: When you use an enumerator, you must not modify the tree during enumeration. 
 */
- (NSEnumerator *) objectEnumerator;

/**
 Creates an NSArray which contains the objects in this queue, either front-to-back or
 in reverse order.
 
 @param reverseOrder The order in which to insert elements into the array.
		<ul>
		<li><code>NO</code> - The 0 index contains the first element in the queue.
		<li><code>YES</code> - The 0 index contains the last element in the queue.
		</ul>
 */
- (NSArray *) contentsAsArrayByReversingOrder:(BOOL)reverseOrder;

/**
 Returns an autoreleased Queue with the contents of the array in the specified order.
 
 @param array An array of objects to add to the queue.
 @param reverseOrder The order in which to enqueue objects from the array.
		<ul>
		<li><code>NO</code> - The queue contains the array object in order (0...n).
		<li><code>YES</code> - The queue contains the array object in order (n...0).
        </ul>
 */
+ (id<Queue>) queueWithArray:(NSArray *)array byReversingOrder:(BOOL)reverseOrder;

@end