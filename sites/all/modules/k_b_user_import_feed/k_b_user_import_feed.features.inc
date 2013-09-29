<?php
/**
 * @file
 * k_b_user_import_feed.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function k_b_user_import_feed_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
