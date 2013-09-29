
/**
 * @file
 * Common marker highlighting routines.
 */

/**
 * Highlights marker on rollover.
 * Removes highlight on previous marker.
 *
 * Creates a "circle" using 20-sided GPolygon at the given point
 * Circle polygon object is global variable as there is only one highlighted marker at a time
 * and we want to remove the previously placed polygon before placing a new one.
 * 
 * Original code "Google Maps JavaScript API Example"
 */
highlightMarker = function (gmap, currentMarker, highlightID, color) {

  var map = gmap.map;

  var markerPoint = currentMarker.marker.getPosition();
  var polyPoints = Array();

  var mapNormalProj = gmap.highlight.overlay.getProjection();

  var mapZoom = map.getZoom();
  var clickedPixel = mapNormalProj.fromLatLngToDivPixel(markerPoint, mapZoom);

  var polySmallRadius = 20;
  var polyNumSides = 20;
  var polySideLength = 18;

  for (var a = 0; a < (polyNumSides + 1); a++) {
    var aRad = polySideLength * a * (Math.PI/180);
    var polyRadius = polySmallRadius; 
    var pixelX = clickedPixel.x + polyRadius * Math.cos(aRad);
    var pixelY = clickedPixel.y + polyRadius * Math.sin(aRad);
    var polyPixel = new google.maps.Point(pixelX, pixelY);
    var polyPoint = mapNormalProj.fromDivPixelToLatLng(polyPixel, mapZoom);
    polyPoints.push(polyPoint);
  }
  // Using GPolygon(points,  strokeColor?,  strokeWeight?,  strokeOpacity?,  fillColor?,  fillOpacity?)
  gmap.highlight.polygon = new google.maps.Polygon( {
    paths: polyPoints,
    strokeColor: color,
    strokeWeight: 2,
    strokeOpacity: 0,
    fillColor: color,
    fillOpacity: 0.5
  } );
  gmap.highlight.polygon.setMap( map );

};

unHighlightMarker = function (gmap, currentMarker, highlightID) {
  if (gmap.highlight.polygon) {
    gmap.highlight.polygon.setMap( null );
    delete gmap.highlight.polygon;
  }
};

Drupal.gmap.addHandler('gmap', function (elem) {

  var obj = this;

  function HighlightOverlay(m) { this.setMap(m); }

  HighlightOverlay.prototype = new google.maps.OverlayView();

  HighlightOverlay.prototype.onAdd = function() { }
  HighlightOverlay.prototype.onRemove = function() { }
  HighlightOverlay.prototype.draw = function() { }

  obj.bind('init', function () {

    obj.highlight = {};
    obj.highlight.overlay = new HighlightOverlay( obj.map );

  });

} );