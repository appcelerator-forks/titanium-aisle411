/***********************************************************************
 *
 * aisle411
 * Copyright (C) by aisle411
 * http://www.aisle411.com
 *
 * Developed by Mercury Development, LLC
 * http://www.mercdev.com
 *
 ***********************************************************************/

#import <UIKit/UIKit.h>

@protocol InformationBarDelegate;
@protocol InformationBarDataSource;
@class OverlayItem;

/*!
 @class InformationBar
 @abstract Information bar class.
 */
@interface InformationBar : UIView


/*!
 @property dataSource
 @abstract The information bar data source.
 */
@property (nonatomic, assign) id <InformationBarDataSource> dataSource;

/*!
 @property delegate
 @abstract The information bar delegate.
 */
@property (nonatomic, assign) id <InformationBarDelegate> delegate;

/*!
 @method dequeueReusableCellWithIdentifier:
 @param identifier A string identifying the cell object to be reused. This parameter must not be nil.
 @return A UITableViewCell object with the associated identifier or nil if no such object exists in the reusable-cell queue.
 */
- (id)dequeueReusableCellWithIdentifier:(NSString *)identifier;

@end


/*!
 @protocol InformationBarDataSource
 @abstract The data source for InformationBar.
 */
@protocol InformationBarDataSource <NSObject>

@required
/*!
 @method informationBar:numberOfRowsForItem:
 @param informationBar an instance of InformationBar.
 @param item an instance of OrverlayItem the InformationBar is shown for.
 @return The InformationBar table part rows count.
 */
- (NSInteger)informationBar:(InformationBar*)informationBar numberOfRowsForItem:(OverlayItem*)item;

/*!
 @method informationBar:cellForRowAtIndex:forItem:
 @param informationBar an instance of InformationBar.
 @param rowIndex row index.
 @param item an instance of OrverlayItem the InformationBar is shown for.
 @return The Table View cell for the InformationBar.
 */
- (UITableViewCell *)informationBar:(InformationBar*)informationBar cellForRowAtIndex:(NSInteger) rowIndex forItem:(OverlayItem*)item;

/*!
 @method informationBar:keywordForItem:
 @param informationBar an instance of InformationBar.
 @param item an instance of OrverlayItem the InformationBar is shown for.
 @return The keyword to display in the InformationBar
 */
- (NSString *)informationBar:(InformationBar*)informationBar keywordForItem:(OverlayItem*)item;

/*!
 @method informationBar:fixedForItem:
 @param informationBar an instance of InformationBar.
 @param item an instance of OrverlayItem the InformationBar is shown for.
 @return The fixed flag for the InformationBar.
 */
- (BOOL)informationBar:(InformationBar*)informationBar fixedForItem:(OverlayItem*)item;

/*!
 @method informationBar:collapsedInstructionsForItem:
 @param informationBar an instance of InformationBar.
 @param item an instance of OrverlayItem the InformationBar is shown for.
 @return The collapsed instructions string for the InformationBar.
 */
- (NSString*)informationBar:(InformationBar*)informationBar collapsedInstructionsForItem:(OverlayItem*)item;

/*!
 @method informationBar:expandedInstructionsForItem:
 @param informationBar an instance of InformationBar.
 @param item an instance of OrverlayItem the InformationBar is shown for.
 @return The expanded instructions string for the InformationBar.
 */
- (NSString*)informationBar:(InformationBar*)informationBar expandedInstructionsForItem:(OverlayItem*)item;

/*!
 @method informationBar:locationForItem:
 @param informationBar an instance of InformationBar.
 @param item an instance of OrverlayItem the InformationBar is shown for.
 @return The location string for the InformationBar.
 */
- (NSString*)informationBar:(InformationBar*)informationBar locationForItem:(OverlayItem*)item;

/*!
 @method informationBar:sublocationForItem:
 @param informationBar an instance of InformationBar.
 @param item an instance of OrverlayItem the InformationBar is shown for.
 @return The sublocation string for the InformationBar.
 */
- (NSString*)informationBar:(InformationBar*)informationBar sublocationForItem:(OverlayItem*)item;
@end



/*!
 @protocol InformationBarDelegate
 @abstract The delegate of InformationBar.
 */
@protocol InformationBarDelegate <NSObject>

@optional

/*!
 @method informationBar:didSelectRowAtIndex:forItem
 @param informationBar an instance of InformationBar.
 @param rowIndex selected row index.
 @param item an instance of OrverlayItem the InformationBar is shown for.
 */
- (void)informationBar: (InformationBar*)informationBar didSelectRowAtIndex:(NSInteger) rowIndex forItem:(OverlayItem*)item;

/*!
 @method informationBarWillShowTable:
 @param informationBar an instance of InformationBar.
 */
- (void)informationBarWillShowTable: (InformationBar*)informationBar;

/*!
 @method informationBarDidShowTable:
 @param informationBar an instance of InformationBar.
 */
- (void)informationBarDidShowTable: (InformationBar*)informationBar;

/*!
 @method informationBarWillHideTable:
 @param informationBar an instance of InformationBar.
 */
- (void)informationBarWillHideTable: (InformationBar*)informationBar;

/*!
 @method informationBarDidHideTable:
 @param informationBar an instance of InformationBar.
 */
- (void)informationBarDidHideTable: (InformationBar*)informationBar;


/*!
 @method informationBar:heightForRowAtIndex:forItem:
 @param informationBar an instance of InformationBar.
 @param rowIndex row index.
 @param item an instance of OrverlayItem the InformationBar is shown for.
 @return Returns height of the cell.
 */
- (CGFloat)informationBar:(InformationBar *)informationBar heightForRowAtIndex:(NSInteger)rowIndex forItem:(OverlayItem*)item;

@end