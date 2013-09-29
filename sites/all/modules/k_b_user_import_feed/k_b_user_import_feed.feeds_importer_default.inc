<?php
/**
 * @file
 * k_b_user_import_feed.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function k_b_user_import_feed_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'customers_import';
  $feeds_importer->config = array(
    'name' => 'Customers import',
    'description' => 'A feeds importer to import customers from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          5 => '5',
          3 => 0,
          4 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'name',
            'target' => 'name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'mail',
            'target' => 'mail',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => 0,
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['customers_import'] = $feeds_importer;

  return $export;
}
