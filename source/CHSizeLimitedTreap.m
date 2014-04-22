/*
 CHDataStructures.framework -- CHSizeLimitedTreap.m
 
 Copyright (c) 2008-2010, Quinn Taylor <http://homepage.mac.com/quinntaylor>
 
 This source code is released under the ISC License. <http://www.opensource.org/licenses/isc-license>
 
 Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.
 
 The software is  provided "as is", without warranty of any kind, including all implied warranties of merchantability and fitness. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the software or the use or other dealings in the software.
 */

#import "CHSizeLimitedTreap.h"

@implementation CHSizeLimitedTreap

- (id) init {
    
    if (self = [super init]) {
        self.maxCount = NSUIntegerMax;
    }
    return self;
}

- (void) setMaxCount:(NSUInteger)maxCount {
    
    _maxCount = maxCount;
    
    if (self.count > maxCount) {
        ++mutations;
        while (self.count > maxCount)
            [self removeLeaf];
    }
}

- (void) addObject:(id)anObject withPriority:(NSUInteger)priority {
    
    [super addObject:anObject withPriority:priority];
    
    if (self.count > self.maxCount)
        [self removeLeaf];
}

- (void) removeLeaf {
    
	if (count == 0)
		return;
	
	CHBinaryTreeNode *parent = nil, *current = header->right;
    
    // pick a random side to delete from
	NSUInteger side = arc4random() % 2;
    if (!current->link[side] || current->link[side] == sentinel)
        side = (side + 1) & 1;
    if (!current->link[side] || current->link[side] == sentinel)
        return;
    
	// find a leaf node
	while (current && ((current->link[0] && current->link[0] != sentinel) || (current->link[1] && current->link[1] != sentinel))) {
        parent = current;
        if (!current->link[side] || current->link[side] == sentinel)
            side = (side + 1) & 1;
        current = current->link[side];
	}
	NSAssert(parent != nil, @"Illegal state, parent should never be nil!");
    
    parent->link[side] = sentinel;
    if (kCHGarbageCollectionNotEnabled) {
        [current->object release];
        free(current);
    }
    --count;
}

@end
