/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2017 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

#import "TiAisle411MapViewProxy.h"
#import "TiUtils.h"
#import "TiAisle411MapView.h"
#import "FMProduct.h"
#import "ProductCalloutOverlay.h"

@implementation TiAisle411MapViewProxy

- (TiAisle411MapView *)mapView
{
  return (TiAisle411MapView *)[self view];
}

#pragma mark Public API's

- (void)setFloor:(id)floor
{
  ENSURE_TYPE(floor, NSNumber);
  [[[self mapView] mapController] setFloor:[TiUtils intValue:floor]];
}

- (void)setLogoPosition:(id)logoPosition
{
  ENSURE_TYPE(logoPosition, NSNumber);
  [[[self mapView] mapController] setLogoPosition:[TiUtils intValue:logoPosition def:AisleLogoRightBottomPosition]];
}

- (void)setCompassEnabled:(id)compassEnabled
{
  ENSURE_TYPE(compassEnabled, NSNumber);
  [[[self mapView] mapController] setCompassEnabled:[TiUtils boolValue:compassEnabled]];
}

- (void)deselectAll:(id)unused
{
  [[[self mapView] mapController] deselectAll];
}

- (void)clear:(id)unused
{
  [[[self mapView] mapController] clear];
}
- (void)zoomIn:(id)unused
{
  [[[self mapView] mapController] zoomIn];
}

- (void)zoomOut:(id)unused
{
  [[[self mapView] mapController] zoomOut];
}

- (void)redraw:(id)args
{
  ENSURE_SINGLE_ARG(args, NSDictionary);
  
  NSMutableArray<FMProduct *> *products = [NSMutableArray array];
  NSArray *inputProducts = [args objectForKey:@"products"];
  
  if (!inputProducts) {
    NSLog(@"[ERROR] Missing required parameter 'products!'");
    return;
  }
  
  for (NSDictionary *inputProduct in inputProducts) {
    FMProduct *product = [[FMProduct alloc] init];
    product.name = [inputProduct objectForKey:@"name"];
    product.idn = [TiUtils intValue:[inputProduct objectForKey:@"id"]];
    
    [products addObject:product];
  }
  
  ProductCalloutOverlay *productCallOutOverlay = [[ProductCalloutOverlay alloc] initWithInformationBarSupport];
  productCallOutOverlay.products = products;
  
  [[[self mapView] mapController] redrawOverlay:productCallOutOverlay];
}

#pragma mark Layout Helper

USE_VIEW_FOR_CONTENT_WIDTH

USE_VIEW_FOR_CONTENT_HEIGHT

- (TiDimension)defaultAutoWidthBehavior:(id)unused
{
  return TiDimensionAutoFill;
}

- (TiDimension)defaultAutoHeightBehavior:(id)unused
{
  return TiDimensionAutoFill;
}

@end
